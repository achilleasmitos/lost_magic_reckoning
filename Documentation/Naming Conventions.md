# Naming Conventions

Below are the most common naming conventions that our project uses. They mostly follow [Google's C++ recommendations](https://google.github.io/styleguide/cppguide.html#Naming), so if ever you are in doubt, it's a safe bet to adhere to what they are saying there.

## Variables

Variable names are all lowercase, with underscores between words. This is often referred to as [snake_case](https://en.wikipedia.org/wiki/Snake_case).
Examples:
- `int my_variable_name = 2;`
- `bool this_is_snake_case = true;`

#### Constant variables

Constant variables are all uppercase, with underscores between words.
Examples:
- `int PI = 3.14;`
- `std::string PLANCK_CONSTANT = "h";`

#### Global Variables

Global variables follow the principles of normal variables, only they include a _**g\_**_ in front of their name.
Examples:
- `int g_my_global_variable_name = 2;`
- `bool g_this_is_snake_case = true;`

#### Class-member Variables

Class-member variables follow the principles of normal variables, only they include a _**m\_**_ in front of their name.
Examples:
- `int m_my_class_member_variable_name = 2;`
- `bool m_this_is_snake_case = true;`

## Type names
Type names follow the [UpperCamelCase / PascalCase](https://en.wikipedia.org/wiki/Camel_case) scheme, where every name is one word that starts with a capital letter, and every sub-word inside it starts with a capital letter as well. Entities that belong to this category are: _enum types, enum values, type aliases, type template parameters, structs and classes_.

## Namespaces

Namespaces follow the [snake_case](https://en.wikipedia.org/wiki/Snake_case) scheme, like variables.
Examples:
- `namespace utils`
- `namespace another_namespace`

## Functions

Functions should follow the [UpperCamelCase / PascalCase](https://en.wikipedia.org/wiki/Camel_case) scheme, like type names. Getter and setter methods of classes should follow the naming scheme of variables.
Examples:
- `void PrintStats();`
- `int CountSteps();`
- `std::string get_name();`

## Files and folders

The names of files and folders should follow the same scheme as variables. Files should ideally have the same name as their main component.
