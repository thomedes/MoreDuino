#include <MoreDuino.h>

using namespace MoreDuino;

Logging::Logger logger(Logging::DEBUG, "LoggingExample");

void setup() {
  logger.debug("Hello, world!");
  logger.info("Hello, world!");
  logger.warning("Hello, world!");
  logger.error("Hello, world!");
  logger.critical("Hello, world!");
}

void loop() {
}
