#ifndef MOREDUINO_LOGGING_H__
#define MOREDUINO_LOGGING_H__

#include <Arduino.h>

namespace MoreDuino {
namespace Logging {

enum Level {
  NOTSET = 0,
  DEBUG = 10,
  INFO = 20,
  WARNING = 30,
  ERROR = 40,
  CRITICAL = 50,
};

class Logger {
public:
  Logger(unsigned level = NOTSET,
         const char *name = nullptr,
         Print &output = Serial)
    : m_level(level), m_name(name), m_output(output) {}
  void debug(const char *format, ...) __attribute__((format(printf, 2, 3)));
  void info(const char *format, ...) __attribute__((format(printf, 2, 3)));
  void warning(const char *format, ...) __attribute__((format(printf, 2, 3)));
  void error(const char *format, ...) __attribute__((format(printf, 2, 3)));
  void critical(const char *format, ...) __attribute__((format(printf, 2, 3)));
  void log(Level level, const char *format, ...) __attribute__((format(printf, 3, 4)));

  void setLevel(unsigned level) { m_level = level; }

private:
  int m_level;  // default to ERROR
  const char *const m_name;
  Print &m_output;

  void vlog(Level level, const char *format, va_list args);
};

}  // namespace Logging
}  // namespace MoreDuino

#endif  // MOREDUINO_LOGGING_H__
