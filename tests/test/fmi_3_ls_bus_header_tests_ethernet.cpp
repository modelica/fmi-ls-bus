#include "fmi_3_ls_bus_header_test_helper_ethernet.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4309)
#pragma warning(disable : 4305)
#endif

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
#endif

/**
 * \brief Test for the Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusEthernetTransmit, minValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	fmi3UInt8 src[] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	fmi3UInt8 dest[] = { 'A', 'B', 'C', 'A', 'B', 'C' };

	CheckEthernetTransmitOperation(0, 0, 0, src, dest, 0, sizeof(data), data, true);
}

//
///**
// * \brief Test for the CAN Transmit operation with biggest valid values.
// */
//TEST(Fmi3LsBusCanTransmit, maxValues) {
//
//	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
//	CheckCanTransmitOperation(UINT32_MAX, UINT8_MAX, UINT8_MAX, sizeof(data), data, true);
//}
//
///**
// * \brief Test for the CAN Transmit operation with values that are too big.
// */
//TEST(Fmi3LsBusCanTransmit, wrongValues) {
//
//	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
//	CheckCanTransmitOperation(WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, sizeof(data), data, false);
//}
//
///**
// * \brief Test for the CAN Transmit operation with data that is too big.
// */
//TEST(Fmi3LsBusCanTransmit, sizeError)
//{
//	CheckDataSizeError(CanTransmit);
//}
