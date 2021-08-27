# qtranslatortest

According to the [documentation](https://doc.qt.io/qt-5/internationalization.html#example-basic-qt-modules)
one can load system translators with `translator.load(locale, "qtbase")`, i.e., without indicating a specific path.

However, on my system it does not work, while it seems to work on others.
This application serves as a test to find out the reason for that.

# Build

Building the application is trivial (`cmake -S SOURCE -B BUILD; cmake --build BUILD`).
Qt5 is the only dependency.

# Usage

The application calls `QTranslator::load(locale, name, prefix, directory, suffix)`.
- `locale` is `QLocale::system()`, you can modify it using environment variables,
- `name` is `"qtbase"`
- `prefix` is `"_"`
- `directory` is user defined
- `suffix` is empty.

For example:
- `LANG=XX ./test` to check whether the `qtbase` translator can be loaded for language "XX" with `directory = ""`,
- `LANG=XX ./test  some/path` to check whether the `qtbase` translator can be loaded for language "XX" with `directory = "some/path"`.
