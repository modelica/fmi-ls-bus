#include <../hdr/fmi_3_ls_bus_header_test_helper_can2.h>
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4309)
#pragma warning(disable : 4305)
#endif

/**
 * \brief Test for the CAN Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusCanTransmit2, minValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanTransmitOperation2(0, 0, 0, data, true);
}


/**
 * \brief Test for the CAN Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusCanTransmit2, maxValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanTransmitOperation2(UINT32_MAX, UINT8_MAX, UINT8_MAX, data, true);
}

/**
 * \brief Test for the CAN Transmit operation with values that are too big.
 */
TEST(Fmi3LsBusCanTransmit2, wrongValues2) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanTransmitOperation2(WRONG_U_INT322, WRONG_U_INT82, WRONG_U_INT82, data, false);
}
