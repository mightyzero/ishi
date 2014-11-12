#include <gtest/gtest.h>

#include <TestCommon.h>
#include <TestArithmetics.h>
#include <TestArray.h>
// #include <TestMatrix.h>
// #include <TestPoint.h>

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
