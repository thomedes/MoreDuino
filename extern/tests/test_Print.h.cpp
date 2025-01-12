#ifndef TEST_PRINT_H
#define TEST_PRINT_H

#include <gtest/gtest.h>
#include "Print.h"

class MockPrint : public Print {
public:
  MockPrint() : buffer(""), write_error_(false) {}

  virtual size_t write(uint8_t c) override {
    buffer += c;
    return 1;
  }

  virtual size_t write(const uint8_t *buffer, size_t size) override {
    for (size_t i = 0; i < size; ++i) {
      write(buffer[i]);
    }
    return size;
  }

  std::string getBuffer() const {
    return buffer;
  }

  void clearBuffer() {
    buffer.clear();
  }

private:
  std::string buffer;
};

TEST(PrintTest, WriteError) {
  MockPrint mockPrint;
  EXPECT_EQ(mockPrint.getWriteError(), 0);
  mockPrint.setWriteError(1);
  EXPECT_EQ(mockPrint.getWriteError(), 1);
  mockPrint.clearWriteError();
  EXPECT_EQ(mockPrint.getWriteError(), 0);
}

TEST(PrintTest, WriteString) {
  MockPrint mockPrint;
  const char *str = "Hello, World!";
  mockPrint.write(str);
  EXPECT_EQ(mockPrint.getBuffer(), str);
}

TEST(PrintTest, WriteBuffer) {
  MockPrint mockPrint;
  const uint8_t buffer[] = { 'H', 'e', 'l', 'l', 'o' };
  mockPrint.write(buffer, sizeof(buffer));
  EXPECT_EQ(mockPrint.getBuffer(), "Hello");
}

#endif // TEST_PRINT_H
