#include <QTranslator>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
  QCoreApplication app(argc, argv);
  const auto locale = QLocale::system();
  QTranslator translator;
  if (argc == 1) {
    if (translator.load(locale, "qtbase", "_")) {
      qDebug() << "Successfully loaded qtbase translator for " << locale;
      exit(EXIT_SUCCESS);
    } else {
      qDebug() << "Failed to load qtbase translator for " << locale;
      exit(EXIT_FAILURE);
    }
  } else if (argc == 2) {
    const char* path = argv[1];
    if (translator.load(locale, "qtbase", "_",  path)) {
      qDebug() << "Successfully loaded qtbase translator for " << locale << " in " <<  path;
      exit(EXIT_SUCCESS);
    } else {
      qDebug() << "Failed to load qtbase translator for " << locale <<  " in " << path;
      exit(EXIT_FAILURE);
    }
  }
}
