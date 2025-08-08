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

/**
 * \brief Test for the Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusEthernetTransmit, maxValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	fmi3UInt8 src[] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	fmi3UInt8 dest[] = { 'A', 'B', 'C', 'A', 'B', 'C' };

	CheckEthernetTransmitOperation(UINT8_MAX, UINT8_MAX, UINT8_MAX, src, dest, UINT16_MAX, sizeof(data), data, true);
}

/**
 * \brief Test for the Transmit operation with values that are too big.
 */
TEST(Fmi3LsBusEthernetTransmit, wrongValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	fmi3UInt8 src[] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	fmi3UInt8 dest[] = { 'A', 'B', 'C', 'A', 'B', 'C' };

	CheckEthernetTransmitOperation(WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, src, dest, WRONG_U_INT16, sizeof(data), data, false);
}

/**
 * \brief Test for the Confirm operation.
 */
TEST(Fmi3LsBusEthernetConfirm, defaultValues) {
	CheckEthernetConfirmOperation();
}

/**
 * \brief Test for the Wakeup operation.
 */
TEST(Fmi3LsBusEthernetWakeUp, defaultValues) {
	CheckEthernetWakeupOperation();
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorCode and isSender.
 */
TEST(Fmi3LsBusEthernetBusError, minValues1) {

	CheckEthernetBusErrorOperation(FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorCode and isSender.
 */
TEST(Fmi3LsBusEthernetBusError, minValues2) {

	CheckEthernetBusErrorOperation(FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_MEDIUM_BUSY, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorCode and isSender.
 */
TEST(Fmi3LsBusEthernetBusError, minValues3) {

	CheckEthernetBusErrorOperation(FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_UNKNOWN, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Format Error operation with data of type Transmit operation.
 */
TEST(Fmi3LsBusEtherneFormatError, Transmit)
{
	CheckFormatErrorOperation(Transmit);
}

/**
 * \brief Test for the Format Error operation with data of type Confirm operation.
 */
TEST(Fmi3LsBusEtherneFormatError, Confirm)
{
	CheckFormatErrorOperation(Confirm);
}

/**
 * \brief Test for the Format Error operation with data of type BusError operation.
 */
TEST(Fmi3LsBusEtherneFormatError, BusError)
{
	CheckFormatErrorOperation(BusError);
}

/**
 * \brief Test for the Format Error operation with data of type Wakeup operation.
 */
TEST(Fmi3LsBusEtherneFormatError, Wakeup)
{
	CheckFormatErrorOperation(Wakeup);
}

/**
 * \brief Test for the Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetTransmit, sizeError)
{
	CheckDataSizeError(Transmit);
}

/**
 * \brief Test for the Confirm operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetConfirm, sizeError)
{
	CheckDataSizeError(Confirm);
}

/**
 * \brief Test for the BusError operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetBusError, sizeError)
{
	CheckDataSizeError(BusError);
}

/**
 * \brief Test for the Wakeup operation with data that is too big.
 */
TEST(Fmi3LsBusEthernetWakeup, sizeError)
{
	CheckDataSizeError(Wakeup);
}