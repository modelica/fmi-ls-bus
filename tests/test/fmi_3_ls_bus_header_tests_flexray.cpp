#include "fmi_3_ls_bus_header_test_helper_flexray.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4309)
#pragma warning(disable : 4305)
#endif

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3True, fmi3True, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3False, fmi3True, fmi3True, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3True, fmi3False, fmi3True, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3False, fmi3False, fmi3True, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3True, fmi3True, fmi3False, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3False, fmi3True, fmi3False, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3True, fmi3False, fmi3False, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3False, fmi3False, fmi3False, fmi3True, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues9) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3True, fmi3True, fmi3True, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues10) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3False, fmi3True, fmi3True, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues11) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3True, fmi3False, fmi3True, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues12) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3False, fmi3False, fmi3True, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues13) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3True, fmi3True, fmi3False, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues14) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3False, fmi3True, fmi3False, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues15) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,   fmi3True, fmi3False, fmi3False, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues16) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0,  fmi3False, fmi3False, fmi3False, fmi3False, 0, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3True, fmi3True, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3True, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3True, fmi3False, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3False, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3True, fmi3True, fmi3False, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3True, fmi3False, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3True, fmi3False, fmi3False, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3False, fmi3False, fmi3True, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues9) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,   fmi3True, fmi3True, fmi3True, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues10) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3True, fmi3True, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues11) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3True, fmi3False, fmi3True, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues12) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3False, fmi3True, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues13) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3True, fmi3True, fmi3False, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues14) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX,  fmi3False, fmi3True, fmi3False, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues15) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3False, fmi3False, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues16) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3False, fmi3False, fmi3False, UINT32_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3True, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3False, fmi3True, fmi3True, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3True, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3False, fmi3False, fmi3True, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3True, fmi3True, fmi3False, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3False, fmi3True, fmi3False, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3False, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3False, fmi3False, fmi3False, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues9) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16,  FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3True, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues10) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3True, fmi3True, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues11) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16,  FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3True, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues12) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };  
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3False, fmi3False, fmi3True, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues13) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3False, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues14) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16,  FLEXRAY_WRONG_U_INT8, fmi3False, fmi3True, fmi3False, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues15) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3True, fmi3False, fmi3False, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues16) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8,  fmi3False, fmi3False, fmi3False, fmi3False, FLEXRAY_WRONG_U_INT32, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayTransmit, sizeError)
{
	CheckDataSizeError(FlexRayTransmit);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Transmit operation.
 */
TEST(Fmi3LsBusFlexRayTransmit, formatError)
{
	CheckFormatErrorOperation(FlexRayTransmit);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayBusError, sizeError)
{
	CheckDataSizeError(BusError);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Bus Error operation.
 */
TEST(Fmi3LsBusFlexRayBusError, formatError)
{
	CheckFormatErrorOperation(BusError);
}

/**
 * \brief Test for the FlexRay Configuration Global operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayConfigurationGlobal, minValues)
{
	CheckFlexRayConfigurationOperation(ConfigurationGlobal, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, fmi3False, true);
}

/**
 * \brief Test for the FlexRay Configuration Global operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayConfigurationGlobal, maxValues)
{
	CheckFlexRayConfigurationOperation(ConfigurationGlobal, UINT32_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT16_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT64_MAX, true);
}

/**
 * \brief Test for the FlexRay Configuration Global operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayConfigurationGlobal, sizeError)
{
	CheckDataSizeError(ConfigurationGlobal);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Configuration Global operation.
 */
TEST(Fmi3LsBusFlexRayConfigurationGlobal, formatError)
{
	CheckFormatErrorOperation(ConfigurationGlobal);
}

/**
 * \brief Test for the FlexRay Configuration Startup operation with value fmi3True.
 */
TEST(Fmi3LsBusFlexRayConfigurationGlobal, trueValue)
{
	CheckFlexRayConfigurationOperation(ConfigurationGlobal, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, fmi3True, NULL);
}

/**
 * \brief Test for the FlexRay Configuration Startup operation with value fmi3False.
 */
TEST(Fmi3LsBusFlexRayConfigurationStartUp, falseValue)
{
	CheckFlexRayConfigurationOperation(ConfigurationGlobal, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, fmi3False, NULL);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, minValues1)
{
	CheckFlexRaySymbolOperation(0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, minValues2)
{
	CheckFlexRaySymbolOperation(0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_MEDIA_TEST_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, minValues3)
{
	CheckFlexRaySymbolOperation(0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, maxValues1)
{
	CheckFlexRaySymbolOperation(UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, maxValues2)
{
	CheckFlexRaySymbolOperation(UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_MEDIA_TEST_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, maxValues3)
{
	CheckFlexRaySymbolOperation(UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, wrongValues1)
{
	CheckFlexRaySymbolOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, wrongValues2)
{
	CheckFlexRaySymbolOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FMI3_LS_BUS_FLEXRAY_SYMBOL_MEDIA_TEST_SYMBOL, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, wrongValues3)
{
	CheckFlexRaySymbolOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRaySymbol, sizeError)
{
	CheckDataSizeError(Symbol);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Symbol operation.
 */
TEST(Fmi3LsBusFlexRaySymbol, formatError)
{
	CheckFormatErrorOperation(Symbol);
}

/**
 * \brief Test for combination of all operations with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayCombinationTest, maxValues) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;

	fmi3LsBusFlexRayOperationFlexRayTransmit* flexRayTransmitOperation;
	fmi3LsBusFlexRayOperationBusError* flexRayBusErrorOperation;
	fmi3LsBusFlexRayOperationConfiguration* flexRayConfigurationOperation;
	fmi3LsBusFlexRayOperationStartCommunication* flexRayStatusOperation;
	fmi3LsBusFlexRayOperationSymbol* flexRaySymbolOperation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_FLEXRAY_CREATE_OP_FLEXRAY_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&firstBufferInfo, FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_GLOBAL(&firstBufferInfo, UINT32_MAX, UINT16_MAX, UINT8_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT8_MAX, UINT16_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT64_MAX, fmi3True);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, UINT64_MAX);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&firstBufferInfo, UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_FLEXRAY_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationFlexRayTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_FLEXRAY_TRANSMIT);
	EXPECT_EQ(flexRayTransmitOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRayTransmitOperation->slotId, UINT16_MAX);
	EXPECT_EQ(flexRayTransmitOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRayTransmitOperation->startupFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->syncFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->nullFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->payloadPreambleIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(flexRayTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayBusErrorOperation = (fmi3LsBusFlexRayOperationBusError*)operationHeader;
	EXPECT_EQ(flexRayBusErrorOperation->errorFlags, FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR);
	EXPECT_EQ(flexRayBusErrorOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRayBusErrorOperation->segmentIndicator, UINT16_MAX);
	EXPECT_EQ(flexRayBusErrorOperation->channel, UINT8_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayConfigurationOperation = (fmi3LsBusFlexRayOperationConfiguration*)operationHeader;
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.macrotickDuration, UINT32_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.macroticksPerCycle, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.actionPointOffset, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.staticSlotLength, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.numberOfStaticSlots, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.staticPayloadLength, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.minislotActionPointOffset, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.numberOfMinislots, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.minislotLength, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.symbolWindowLength, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.coldstartNode, fmi3True);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayStatusOperation = (fmi3LsBusFlexRayOperationStartCommunication*)operationHeader;
	EXPECT_EQ(flexRayStatusOperation->startTime, UINT64_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRaySymbolOperation = (fmi3LsBusFlexRayOperationSymbol*)operationHeader;
	EXPECT_EQ(flexRaySymbolOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->type, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationFlexRayTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_FLEXRAY_TRANSMIT);
	EXPECT_EQ(flexRayTransmitOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRayTransmitOperation->slotId, UINT16_MAX);
	EXPECT_EQ(flexRayTransmitOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRayTransmitOperation->startupFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->syncFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->nullFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->payloadPreambleIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(flexRayTransmitOperation->data[i], data[i]);
	}
}

/**
 * \brief Test for combination of all operations with biggest valid and wrong values.
 */
TEST(Fmi3LsBusFlexRayCombinationTest, maxAndWrongValues) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;

	fmi3LsBusFlexRayOperationFlexRayTransmit* flexRayTransmitOperation;
	fmi3LsBusFlexRayOperationBusError* flexRayBusErrorOperation;
	fmi3LsBusFlexRayOperationConfiguration* flexRayConfigurationOperation;
	fmi3LsBusFlexRayOperationStartCommunication* flexRayStatusOperation;
	fmi3LsBusFlexRayOperationSymbol* flexRaySymbolOperation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_FLEXRAY_CREATE_OP_FLEXRAY_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, UINT32_MAX, sizeof(data), data);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&firstBufferInfo, FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_GLOBAL(&firstBufferInfo, FLEXRAY_WRONG_U_INT32, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT32, fmi3True);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, (UINT64_MAX + 1));
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&firstBufferInfo, UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_FLEXRAY_TRANSMIT(&firstBufferInfo, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3True, fmi3True, FLEXRAY_WRONG_U_INT32, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationFlexRayTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_FLEXRAY_TRANSMIT);
	EXPECT_EQ(flexRayTransmitOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRayTransmitOperation->slotId, UINT16_MAX);
	EXPECT_EQ(flexRayTransmitOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRayTransmitOperation->startupFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->syncFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->nullFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->payloadPreambleIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(flexRayTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayBusErrorOperation = (fmi3LsBusFlexRayOperationBusError*)operationHeader;
	EXPECT_EQ(flexRayBusErrorOperation->errorFlags, FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR);
	EXPECT_EQ(flexRayBusErrorOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRayBusErrorOperation->segmentIndicator, UINT16_MAX);
	EXPECT_EQ(flexRayBusErrorOperation->channel, UINT8_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayConfigurationOperation = (fmi3LsBusFlexRayOperationConfiguration*)operationHeader;
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.macrotickDuration, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.macroticksPerCycle, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.actionPointOffset, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.staticSlotLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.numberOfStaticSlots, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.staticPayloadLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.minislotActionPointOffset, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.numberOfMinislots, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.minislotLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.symbolWindowLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayGlobal.coldstartNode, fmi3True);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayStatusOperation = (fmi3LsBusFlexRayOperationStartCommunication*)operationHeader;
	EXPECT_EQ(flexRayStatusOperation->startTime, 0);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRaySymbolOperation = (fmi3LsBusFlexRayOperationSymbol*)operationHeader;
	EXPECT_EQ(flexRaySymbolOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->type, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationFlexRayTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_FLEXRAY_TRANSMIT);
	EXPECT_EQ(flexRayTransmitOperation->cycleId, 0);
	EXPECT_EQ(flexRayTransmitOperation->slotId, 0);
	EXPECT_EQ(flexRayTransmitOperation->channel, 0);
	EXPECT_EQ(flexRayTransmitOperation->startupFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->syncFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->nullFrameIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->payloadPreambleIndicator, fmi3True);
	EXPECT_EQ(flexRayTransmitOperation->dataLength, sizeof(data));
	for (size_t i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(flexRayTransmitOperation->data[i], data[i]);
	}
}

/**
 * \brief Test for resetting a buffer.
 */
TEST(Fmi3LsBusFlexRayCombinationTest, resetBuffer) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_FLEXRAY_CREATE_OP_FLEXRAY_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_BUFFER_INFO_RESET(&firstBufferInfo);
	EXPECT_EQ(firstBufferInfo.readPos, firstBufferInfo.writePos);

	FMI3_LS_BUS_BUFFER_INFO_RESET(&secondBufferInfo);
	EXPECT_EQ(secondBufferInfo.readPos, secondBufferInfo.writePos);
}