#!/bin/sh
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
# Move into this script's directory, work with relative paths afterwards
cd "${parent_path}"
build_folder="../build"
application_name="Lost Magic Reckoning"
release_folder="${build_folder}/${application_name}"
release_executable="lost-magic_reckoning_Release.exe"

echo "Installer initiated."
echo "Make sure that you have run an updated version of the Release Build task."

echo "Creating the Release folder..."
# First, remove any release folder previously created
rm -rf "${release_folder}"
if [ $? -ne 0 ]; then
	echo "Failed to remove previous Release folder. Make sure it isn't in use by any other program, then try again."
	echo "The installer will now exit..."
	echo "ERROR CODE 1: Failed to remove previous Release folder!"
	exit 1
fi
# Then, create a new one
mkdir "${release_folder}"
if [ $? -ne 0 ]; then
	echo "Failed to create new Release folder. Perhaps there is already another folder with the same name?"
	echo "The installer will now exit..."
	echo "ERROR CODE 2: Failed to create new Release folder!"
	exit 2
fi

echo "Copying the Release executable into the Release folder..."
# First, copy the executable
cp "${build_folder}/${release_executable}" "${release_folder}"
if [ $? -ne 0 ]; then
	echo "Failed to copy the Release executable. Make sure it exists, and it has the name: ${release_executable}"
	echo "The installer will now exit..."
	echo "ERROR CODE 3: Failed to copy the Release executable!"
	exit 3
fi
# Then, rename the executable
mv "${release_folder}/${release_executable}" "${release_folder}/${application_name}.exe"
if [ $? -ne 0 ]; then
	echo "Failed to rename the executable. Check the output above."
	echo "The installer will now exit..."
	echo "ERROR CODE 4: Failed to rename the executable!"
	exit 4
fi

echo "Copying the resources into the Release folder..."
cp -r "${build_folder}/../src/resources/" "${release_folder}/resources/"
if [ $? -ne 0 ]; then
	echo "Failed to copy the resources folder. Make sure it exists, and it has the path: src/resources/"
	echo "The installer will now exit..."
	echo "ERROR CODE 5: Failed to copy the resources folder!"
	exit 5
fi

# Finally, copy the instructions for the end-ser
cp "Instructions.txt" "${release_folder}/Instructions.txt"
if [ $? -ne 0 ]; then
	echo "Failed to copy the end-user instructions. Make sure the file exists, and it has the name: Instructions.txt"
	echo "The installer will now exit..."
	echo "ERROR CODE 6: Failed to copy the end-user instructions!"
	exit 6
fi

echo "Zipping the Release folder..."
# cd into the build folder to make the zipped directory structure the desirable one
cd "${build_folder}"
tar --create --file="${application_name}.zip" --verbose "${application_name}/"
if [ $? -ne 0 ]; then
	echo "Failed to zip the Release folder. Check the output above."
	echo "The installer will now exit..."
	echo "ERROR CODE 7: Failed to zip the Release folder!"
	exit 7
fi
# Undo the last `cd` just in case we will add more commands after this
cd "${parent_path}"

echo "Done!"
