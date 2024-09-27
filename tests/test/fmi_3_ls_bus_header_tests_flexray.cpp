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
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3True, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3False, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3False, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3True, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3True, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3False, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3False, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues9) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3True, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues10) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3True, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues11) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3False, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues12) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3False, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues13) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3True, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues14) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3True, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues15) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3True, fmi3False, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, minValues16) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(0, 0, 0, fmi3False, fmi3False, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3True, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3False, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3False, fmi3True, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3True, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3False, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3False, fmi3False, fmi3True, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues9) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues10) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3True, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues11) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3False, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues12) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3False, fmi3True, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues13) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues14) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3True, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues15) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3False, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayTransmit, maxValues16) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3False, fmi3False, fmi3False, fmi3False, sizeof(data), data, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues1) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3True, fmi3True, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues3) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3True, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues4) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3False, fmi3True, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues5) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3False, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues6) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3True, fmi3False, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues7) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3False, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues8) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3False, fmi3False, fmi3True, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues9) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3True, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues10) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3True, fmi3True, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues11) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3True, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues12) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3False, fmi3True, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues13) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3False, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues14) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3True, fmi3False, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues15) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3False, fmi3False, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayTransmit, wrongValues16) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckFlexRayTransmitOperation(FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3False, fmi3False, fmi3False, fmi3False, sizeof(data), data, false);
}

/**
 * \brief Test for the FlexRay Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayTransmit, sizeError)
{
	CheckDataSizeError(Transmit);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Transmit operation.
 */
TEST(Fmi3LsBusFlexRayTransmit, formatError)
{
	CheckFormatErrorOperation(Transmit);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues1) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues2) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues3) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues4) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues5) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues6) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues7) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, minValues8) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, 0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues1) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues2) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues3) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues4) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues5) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues6) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues7) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayBusError, maxValues8) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, UINT8_MAX, UINT16_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues1) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues2) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_SYNTAX_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues3) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues4) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues5) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues6) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_BOUNDARY_VIOLATION, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues7) {

	CheckFlexRayBusErrorOperation(FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_TX_CONFLICT, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, false);
}

/**
 * \brief Test for the FlexRay Bus Error operation with wrong values.
 */
TEST(Fmi3LsBusFlexRayBusError, wrongValues8) {

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
 * \brief Test for the FlexRay Cancel operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayCancel, minValues1)
{
	CheckFlexRayCancelOperation(0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Cancel operation with valid values.
 */
TEST(Fmi3LsBusFlexRayCancel, minValues2)
{
	CheckFlexRayCancelOperation(5, 34, FMI3_LS_BUS_FLEXRAY_CHANNEL_A, true);
}

/**
 * \brief Test for the FlexRay Cancel operation with valid values.
 */
TEST(Fmi3LsBusFlexRayCancel, minValues3)
{
	CheckFlexRayCancelOperation(54, 19, FMI3_LS_BUS_FLEXRAY_CHANNEL_B, true);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Cancel operation.
 */
TEST(Fmi3LsBusFlexRayCancel, formatError)
{
	CheckFormatErrorOperation(Cancel);
}

/**
 * \brief Test for the FlexRay Cancel operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayCancel, sizeError)
{
	CheckDataSizeError(Cancel);
}

/**
 * \brief Test for the FlexRay Confirm operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayConfirm, minValues1)
{
	CheckFlexRayConfirmOperation(0, 0, 0, true);
}

/**
 * \brief Test for the FlexRay Confirm operation with valid values.
 */
TEST(Fmi3LsBusFlexRayConfirm, minValues2)
{
	CheckFlexRayConfirmOperation(13, 9, FMI3_LS_BUS_FLEXRAY_CHANNEL_A, true);
}

/**
 * \brief Test for the FlexRay Confirm operation with valid values.
 */
TEST(Fmi3LsBusFlexRayConfirm, minValues3)
{
	CheckFlexRayConfirmOperation(63, 19, FMI3_LS_BUS_FLEXRAY_CHANNEL_B, true);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Confirm operation.
 */
TEST(Fmi3LsBusFlexRayConfirm, formatError)
{
	CheckFormatErrorOperation(Confirm);
}

/**
 * \brief Test for the FlexRay Confirm operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayConfirm, sizeError)
{
	CheckDataSizeError(Confirm);
}

/**
 * \brief Test for the FlexRay Configuration Config operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRayConfigurationConfig, minValues)
{
	CheckFlexRayConfigurationOperation(ConfigurationConfig, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, fmi3False, true);
}

/**
 * \brief Test for the FlexRay Configuration Config operation with biggest valid values.
 */
TEST(Fmi3LsBusFlexRayConfigurationConfig, maxValues)
{
	CheckFlexRayConfigurationOperation(ConfigurationConfig, UINT32_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT16_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT32_MAX, UINT8_MAX, true);
}

/**
 * \brief Test for the FlexRay Configuration Config operation with data that is too big.
 */
TEST(Fmi3LsBusFlexRayConfigurationConfig, sizeError)
{
	CheckDataSizeError(ConfigurationConfig);
}

/**
 * \brief Test for the Format Error operation with the FlexRay Configuration Config operation.
 */
TEST(Fmi3LsBusFlexRayConfigurationConfig, formatError)
{
	CheckFormatErrorOperation(ConfigurationConfig);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRaySymbol, minValues1)
{
	CheckFlexRaySymbolOperation(0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_COLLISION_AVOIDANCE_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusFlexRaySymbol, minValues2)
{
	CheckFlexRaySymbolOperation(0, 0, FMI3_LS_BUS_FLEXRAY_SYMBOL_MEDIA_TEST_SYMBOL, true);
}

/**
 * \brief Test for the FlexRay Transmit operation with smallest valid values.
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

	fmi3LsBusFlexRayOperationTransmit* flexRayTransmitOperation;
	fmi3LsBusFlexRayOperationBusError* flexRayBusErrorOperation;
	fmi3LsBusFlexRayOperationConfiguration* flexRayConfigurationOperation;
	fmi3LsBusFlexRayOperationStartCommunication* flexRayStatusOperation;
	fmi3LsBusFlexRayOperationSymbol* flexRaySymbolOperation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&firstBufferInfo, FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_CONFIG(&firstBufferInfo, UINT32_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT16_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT16_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT32_MAX, FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_COLDSTART_NODE_TYPE_NONE);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, UINT64_MAX);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&firstBufferInfo, UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_TRANSMIT);
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
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.macrotickDuration, UINT32_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.macroticksPerCycle, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.actionPointOffset, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.staticSlotLength, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.numberOfStaticSlots, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.staticPayloadLength, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.minislotActionPointOffset, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.numberOfMinislots, UINT16_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.minislotLength, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.symbolWindowLength, UINT8_MAX);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.coldstartNode, fmi3True);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayStatusOperation = (fmi3LsBusFlexRayOperationStartCommunication*)operationHeader;
	EXPECT_EQ(flexRayStatusOperation->startTime, UINT64_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRaySymbolOperation = (fmi3LsBusFlexRayOperationSymbol*)operationHeader;
	EXPECT_EQ(flexRaySymbolOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->type, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_TRANSMIT);
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

	fmi3LsBusFlexRayOperationTransmit* flexRayTransmitOperation;
	fmi3LsBusFlexRayOperationBusError* flexRayBusErrorOperation;
	fmi3LsBusFlexRayOperationConfiguration* flexRayConfigurationOperation;
	fmi3LsBusFlexRayOperationStartCommunication* flexRayStatusOperation;
	fmi3LsBusFlexRayOperationSymbol* flexRaySymbolOperation;

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_BUS_ERROR(&firstBufferInfo, FMI3_LS_BUS_FLEXRAY_BUSERROR_PARAM_CONTENT_ERROR, UINT8_MAX, UINT16_MAX, UINT8_MAX);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_CONFIGURATION_FLEXRAY_CONFIG(&firstBufferInfo, FLEXRAY_WRONG_U_INT32, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT32, FMI3_LS_BUS_FLEXRAY_CONFIG_PARAM_COLDSTART_NODE_TYPE_NONE);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_START_COMMUNICATION(&firstBufferInfo, (UINT64_MAX + 1));
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_SYMBOL(&firstBufferInfo, UINT8_MAX, UINT8_MAX, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);
	FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&firstBufferInfo, FLEXRAY_WRONG_U_INT8, FLEXRAY_WRONG_U_INT16, FLEXRAY_WRONG_U_INT8, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_TRANSMIT);
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
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.macrotickDuration, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.macroticksPerCycle, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.actionPointOffset, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.staticSlotLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.numberOfStaticSlots, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.staticPayloadLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.minislotActionPointOffset, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.numberOfMinislots, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.minislotLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.symbolWindowLength, 0);
	EXPECT_EQ(flexRayConfigurationOperation->flexRayConfig.coldstartNode, fmi3True);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayStatusOperation = (fmi3LsBusFlexRayOperationStartCommunication*)operationHeader;
	EXPECT_EQ(flexRayStatusOperation->startTime, 0);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRaySymbolOperation = (fmi3LsBusFlexRayOperationSymbol*)operationHeader;
	EXPECT_EQ(flexRaySymbolOperation->cycleId, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->channel, UINT8_MAX);
	EXPECT_EQ(flexRaySymbolOperation->type, FMI3_LS_BUS_FLEXRAY_SYMBOL_WAKEUP_SYMBOL);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	flexRayTransmitOperation = (fmi3LsBusFlexRayOperationTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_FLEXRAY_OP_TRANSMIT);
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

	FMI3_LS_BUS_FLEXRAY_CREATE_OP_TRANSMIT(&firstBufferInfo, UINT8_MAX, UINT16_MAX, UINT8_MAX, fmi3True, fmi3True, fmi3True, fmi3True, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_BUFFER_INFO_RESET(&firstBufferInfo);
	EXPECT_EQ(firstBufferInfo.readPos, firstBufferInfo.writePos);

	FMI3_LS_BUS_BUFFER_INFO_RESET(&secondBufferInfo);
	EXPECT_EQ(secondBufferInfo.readPos, secondBufferInfo.writePos);
}