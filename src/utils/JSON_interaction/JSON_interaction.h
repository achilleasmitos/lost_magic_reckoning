#pragma once

#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <unordered_map>

namespace utils
{
/**
 * @brief Writes the given object to a simple JSON file under the specified path, using
 * the supplied methods to convert keys and values to their string counterparts.
 *
 * A simple JSON file is a JSON whose values are not objects.
 *
 * @tparam TypeOfKey The type of the keys of the given map
 * @tparam TypeOfValue The type of the values of the given map
 * @param object A map whose key-value pairs will be used for the JSON key-value pairs
 * @param keyToString The function that converts each key to its string counterpart
 * @param valueToString The function that converts each value to its string counterpart
 * @param file_path The path to the file that is to be created/modified
 */
template<typename TypeOfKey, typename TypeOfValue>
void WriteToJSON(const std::unordered_map<TypeOfKey, TypeOfValue>& object,
	const std::function<std::string(TypeOfKey)>& keyToString,
	const std::function<std::string(TypeOfValue)>& valueToString,
	const std::string& file_path)
{
	std::ofstream file(file_path, std::ios::trunc);

	file << "{\n";

	for (auto it = object.begin(); it != object.end(); it++)
	{
		file << "\t\"" << keyToString(it->first) << "\": \"" << valueToString(it->second);

		const bool isLastElement = std::next(it) == object.end();
		// No comma for the last element of JSON
		const char* line_end = isLastElement ? "\"\n" : "\",\n";

		file << line_end;
	}

	file << "}";

	file.close();
}

/**
 * @brief Convenience function for the most standard WriteToJSON usage,
 * that only deals with string-to-string maps.
 *
 * @param object A map whose key-value pairs will be used for the JSON key-value pairs
 * @param file_path The path to the file that is to be created/modified
 */
inline void WriteToJSON(const std::unordered_map<std::string, std::string>& object,
	const std::string& file_path)
{
	const std::function<std::string(std::string)> StringIdentityFunction =
		[](std::string str) -> std::string { return str; };

	WriteToJSON(object, StringIdentityFunction, StringIdentityFunction, file_path);
}

/**
 * @brief Reads a simple JSON file from the specified path
 * and constructs an unorderd map using the supplied methods to convert
 * the JSON key-value pairs to those of the object. It then returns said object.
 * If the file does not exist, is not JSON or is corrupted, then an empty map
 * is returned.
 *
 * A simple JSON file is a JSON whose values are not objects.
 *
 * @tparam TypeOfKey The type of the keys of the constructed map
 * @tparam TypeOfValue The type of the values of the constructed map
 * @param file_path The path to the file that is to be read
 * @param stringToKey The function that converts a string to its key counterpart
 * @param stringToValue The function that converts a string to its value counterpart
 * @return std::unordered_map<TypeOfKey, TypeOfValue> The object created from the JSON
 */
template<typename TypeOfKey, typename TypeOfValue>
std::unordered_map<TypeOfKey, TypeOfValue> ReadFromJSON(const std::string& file_path,
	const std::function<TypeOfKey(std::string)>& stringToKey,
	const std::function<TypeOfValue(std::string)>& stringToValue)
{
	std::unordered_map<TypeOfKey, TypeOfValue> object;
	if (file_path.length() < 5 || file_path.substr(file_path.length() - 5) != ".json")
	{
		return object; // File was not JSON
	}

	std::ifstream file(file_path);
	if (!file.good())
	{
		file.clear();
		file.close();
		return object; // No file found, or file was corrupted
	}

	std::string line;
	const auto key = [](std::string current_line) -> std::string
	{
		const size_t start = current_line.find("\"");
		const size_t end = current_line.find("\"", start + 1);
		return current_line.substr(start + 1, end - start - 1);
	};
	const auto value = [](std::string current_line) -> std::string
	{
		const size_t start = current_line.find(": \"");
		const size_t end = current_line.find("\"", start + 3);
		return current_line.substr(start + 3, end - start - 3);
	};

	std::getline(file, line); // Read (and discard) first line of JSON

	while (std::getline(file, line) && line != "}")
	{
		try
		{
			object.insert({stringToKey(key(line)), stringToValue(value(line))});
		}
		catch (...)
		{
			std::cerr << "Error reading line " << line << "\n";
		}
	}

	file.close();

	return object;
}

/**
 * @brief Convenience function for the most standard ReadFromJSON usage,
 * that only deals with string-to-string maps.
 *
 * @param file_path The path to the file that is to be read
 * @return std::unordered_map<std::string, std::string> The object created from
 * the key-value pairs of the JSON
 */
inline std::unordered_map<std::string, std::string> ReadFromJSON(const std::string& file_path)
{
	const std::function<std::string(std::string)> StringIdentityFunction =
		[](std::string str) -> std::string { return str; };

	return ReadFromJSON(file_path, StringIdentityFunction, StringIdentityFunction);
}
} // namespace utils
