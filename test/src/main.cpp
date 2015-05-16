#include <gtest/gtest.h>

#include <test_common.h>
#include <test_math.h>
#include <test_array.h>
#include <test_matrix.h>
#include <test_zip.h>
// #include <TestPoint.h>

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
