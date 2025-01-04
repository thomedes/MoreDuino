#include "MoreDuino/Logging.h"

#include <cstdarg>

using namespace MoreDuino::Logging;

void Logger::debug(const char *format, ...) {
  if (m_level > DEBUG) return;

  va_list args;
  va_start(args, format);
  vlog(DEBUG, format, args);
  va_end(args);
}

void Logger::info(const char *format, ...) {
  if (m_level > INFO) return;

  va_list args;
  va_start(args, format);
  vlog(INFO, format, args);
  va_end(args);
}

void Logger::warning(const char *format, ...) {
  if (m_level > WARNING) return;

  va_list args;
  va_start(args, format);
  vlog(WARNING, format, args);
  va_end(args);
}

void Logger::error(const char *format, ...) {
  if (m_level > ERROR) return;

  va_list args;
  va_start(args, format);
  vlog(ERROR, format, args);
  va_end(args);
}

void Logger::critical(const char *format, ...) {
  if (m_level > CRITICAL) return;

  va_list args;
  va_start(args, format);
  vlog(CRITICAL, format, args);
  va_end(args);
}

void Logger::log(Level level, const char *format, ...) {
  if (m_level > level) return;

  va_list args;
  va_start(args, format);
  vlog(level, format, args);
  va_end(args);
}

void Logger::vlog(Level level, const char *format, va_list args) {
  m_output.print(m_name);
  m_output.print(": ");
  m_output.print(level);
  m_output.print(": ");
  // m_output.vprintf(format, args);
  m_output.println();
}
