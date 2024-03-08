#include <../hdr/fmi_3_ls_bus_header_test_helper_can.h>
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4309)
#pragma warning(disable : 4305)
#endif

/**
 * \brief Test for the CAN Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusCanTransmit, minValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanTransmitOperation(0, 0, 0, data, true);
}


/**
 * \brief Test for the CAN Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusCanTransmit, maxValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanTransmitOperation(UINT32_MAX, UINT8_MAX, UINT8_MAX, data, true);
}

/**
 * \brief Test for the CAN Transmit operation with values that are too big.
 */
TEST(Fmi3LsBusCanTransmit, wrongValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanTransmitOperation(WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, data, false);
}

/**
 * \brief Test for the CAN Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusCanTransmit, sizeError)
{
	CheckDataSizeError(CanTransmit);
}

/**
 * \brief Test for the CAN FD Transmit Operation with smallest valid values.
 */
TEST(Fmi3LsBusCanFdTransmit, minValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanFdTransmitOperation(0, 0, 0, 0, data, true);
}

/**
 * \brief Test for the CAN FD Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusCanFdTransmit, maxValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanFdTransmitOperation(UINT32_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, data, true);
}

/**
 * \brief Test for the CAN FD Transmit operation with values that are too big.
 */
TEST(Fmi3LsBusCanFdTransmit, wrongValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanFdTransmitOperation(WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, data, false);
}

/**
 * \brief Test for the CAN FD Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusCanFdTransmit, sizeError)
{
	CheckDataSizeError(CanFdTransmit);
}

/**
 * \brief Test for the CAN XL Transmit operation with smallest valid values.
 */
TEST(Fmi3LsBusCanXlTransmit, minValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanXlTransmitOperation(0, 0, 0, 0, 0, 0, data, true);	
}

/**
 * \brief Test for the CAN XL Transmit operation with biggest valid values.
 */
TEST(Fmi3LsBusCanXlTransmit, maxValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanXlTransmitOperation(UINT32_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, data, true);
}

/**
 * \brief Test for the CAN XL Transmit operation with values that are too big.
 */
TEST(Fmi3LsBusCanXlTransmit, wrongValues) {

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };
	CheckCanXlTransmitOperation(WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8,WRONG_U_INT32, data, false);
}

/**
 * \brief Test for the CAN XL Transmit operation with data that is too big.
 */
TEST(Fmi3LsBusCanXlTransmit, sizeError)
{
	CheckDataSizeError(CanXlTransmit);
}

/**
 * \brief Test for the Confirm operation with smallest valid values.
 */
TEST(Fmi3LsBusCanConfirm, minValues) {

	CheckConfirmOperation(0, true);
}

/**
 * \brief Test for the Confirm operation with biggest valid values.
 */
TEST(Fmi3LsBusCanConfirm, maxValues) {

	CheckConfirmOperation(UINT32_MAX, true);
}

/**
 * \brief Test for the Confirm operation with values that are too big.
 */
TEST(Fmi3LsBusCanConfirm, wrongValues) {

	CheckConfirmOperation(WRONG_U_INT32, false);
}

/**
 * \brief Test for the CAN confirm operation with data that is too big.
 */
TEST(Fmi3LsBusCanConfirm, sizeError)
{
	CheckDataSizeError(Confirm);
}

/**
 * \brief Test for the Arbitration Lost operation with smallest valid values.
 */
TEST(Fmi3LsBusCanArbitrationLost, minValues) {

	CheckArbitrationLostBehaviorOperation(0, true);
}

/**
 * \brief Test for the Arbitration Lost operation with biggest valid values.
 */
TEST(Fmi3LsBusCanArbitrationLost, maxValues) {

	CheckArbitrationLostBehaviorOperation(UINT32_MAX, true);
}

/**
 * \brief Test for the Arbitration Lost operation with values that are too big.
 */
TEST(Fmi3LsBusCanArbitrationLost, wrongValues) {

	CheckArbitrationLostBehaviorOperation(WRONG_U_INT32, false);
}

/**
 * \brief Test for the Arbitration Lost operation with data that is too big.
 */
TEST(Fmi3LsBusCanArbitrationLost, sizeError)
{
	CheckDataSizeError(ArbitrationLost);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues1) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues2) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);

}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues3) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues4) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues5) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues6) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues7) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues8) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues9) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues10) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues11) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues12) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues13) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues14) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);

}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues15) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues16) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues17) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues18) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues19) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues20) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues21) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues22) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues23) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with smallest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, minValues24) {

	CheckBusErrorOperation(0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues1) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues2) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);

}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues3) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues4) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues5) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues6) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues7) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues8) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues9) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues10) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues11) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues12) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues13) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues14) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);

}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues15) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues16) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues17) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues18) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues19) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues20) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues21) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues22) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues23) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with biggest valid values and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, maxValues24) {

	CheckBusErrorOperation(UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, true);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues1) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues2) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);

}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues3) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues4) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues5) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues6) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues7) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues8) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues9) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues10) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues11) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues12) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_TRUE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues13) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues14) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);

}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues15) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues16) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_STUFFING_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues17) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues18) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_FORM_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues19) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues20) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_CRC_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues21) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues22) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_ACK_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues23) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with values that are too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, wrongValues24) {

	CheckBusErrorOperation(WRONG_U_INT32, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BROKEN_ERROR_FRAME, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_SECONDARY_ERROR_FLAG, FMI3_LS_BUS_FALSE, false);
}

/**
 * \brief Test for the Bus Error operation with data that is too big and variation for errorFlag, errorCode and isSender.
 */
TEST(Fmi3LsBusCanBusError, sizeError)
{
	CheckDataSizeError(BusError);
}

/**
 * \brief Test for the Configuration operation with smallest valid values.
 */
TEST(Fmi3LsBusCanConfiguration, baudrateMinValues) {

	CheckConfigurationBaudrateOperation(0, true);
}

/**
 * \brief Test for the Configuration operation with biggest valid values.
 */
TEST(Fmi3LsBusCanConfiguration, baudrateMaxValues) {

	CheckConfigurationBaudrateOperation(UINT32_MAX, true);
}

/**
 * \brief Test for the Configuration operation with values that are too big.
 */
TEST(Fmi3LsBusCanConfiguration, baudrateWrongValues) {

	CheckConfigurationBaudrateOperation(WRONG_U_INT32, false);
}

/**
 * \brief Test for the Configuration operation with data that is too big.
 */
TEST(Fmi3LsBusCanConfiguration, baudrateSizeError)
{
	CheckDataSizeError(ConfigurationBaudrate);
}

/**
 * \brief Test for the Configuration operation with smallest valid values.
 */
TEST(Fmi3LsBusCanConfiguration, fdBaudrateMinValues) {
	CheckConfigurationFdBaudrateOperation(0, true);
}

/**
 * \brief Test for the Configuration operation with biggest valid values.
 */
TEST(Fmi3LsBusCanConfiguration, fdBaudrateMaxValues) {
	CheckConfigurationFdBaudrateOperation(UINT32_MAX, true);
}

/**
 * \brief Test for the Configuration operation with values that are too big.
 */
TEST(Fmi3LsBusCanConfiguration, fdBaudrateWrongValues) {
	CheckConfigurationFdBaudrateOperation(WRONG_U_INT32, false);
}

/**
 * \brief Test for the Configuration operation with data that is too big.
 */
TEST(Fmi3LsBusCanConfiguration, fdBaudrateSizeError)
{
	CheckDataSizeError(ConfigurationFdBaudrate);
}

/**
 * \brief Test for the Configuration operation with smallest valid values.
 */
TEST(Fmi3LsBusCanConfiguration, xlBaudrateMinValues) {
	CheckConfigurationXlBaudrateOperation(0, true);
}

/**
 * \brief Test for the Configuration operation with biggest valid values.
 */
TEST(Fmi3LsBusCanConfiguration, xlBaudrateMaxValues) {
	CheckConfigurationXlBaudrateOperation(UINT32_MAX, true);
}

/**
 * \brief Test for the Configuration operation with values that are too big.
 */
TEST(Fmi3LsBusCanConfiguration, xlBaudrateWrongValues) {
	CheckConfigurationXlBaudrateOperation(WRONG_U_INT32, false);
}

/**
 * \brief Test for the Configuration operation with data that is too big.
 */
TEST(Fmi3LsBusCanConfiguration, xlBaudrateSizeError)
{
	CheckDataSizeError(ConfigurationXlBaudrate);
}

/**
 * \brief Test for the Configuration operation with arbitration lost behavior 'BufferAndRetransmit'.
 */
TEST(Fmi3LsBusCanConfiguration, arbitrationLostBehaviorBufferAndRetransmit) {
	CheckConfigurationArbitrationLostBehaviorOperation(FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);
}

/**
 * \brief Test for the Configuration operation with arbitration lost behavior 'DiscardAndNotify'.
 */
TEST(Fmi3LsBusCanConfiguration, arbitrationLostBehaviorDiscardAndNotify) {
	CheckConfigurationArbitrationLostBehaviorOperation(FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_DISCARD_AND_NOTIFY);
}

/**
 * \brief Test for the Configuration operation with data that is too big.
 */
TEST(Fmi3LsBusCanConfiguration, arbitrationLostBehaviorSizeError)
{
	CheckDataSizeError(ConfigurationArbitrationLostBehavior);
}

/**
 * \brief Test for the Status operation with status 'errorActive'.
 */
TEST(Fmi3LsBusCanStatus, errorActive) {
	CheckStatusOperation(FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE);
}

/**
 * \brief Test for the Status operation with status 'errorPassive'.
 */
TEST(Fmi3LsBusCanStatus, errorPassive) {
	CheckStatusOperation(FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_PASSIVE);
}

/**
 * \brief Test for the Status operation with status 'busOff'.
 */
TEST(Fmi3LsBusCanStatus, busOff) {
	CheckStatusOperation(FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_BUS_OFF);
}

/**
 * \brief Test for the Status operation with data that is too big.
 */
TEST(Fmi3LsBusCanStatus, sizeError)
{
	CheckDataSizeError(Status);
}

/**
 * \brief Test for the Wakeup operation.
 */
TEST(Fmi3LsBusCanWakeUp, defaultValues) {
	CheckWakeupOperation();
}

/**
 * \brief Test for the Wakeup operation with data that is too big.
 */
TEST(Fmi3LsBusCanWakeUp, sizeError)
{
	CheckDataSizeError(Wakeup);
};

/**
 * \brief Test for the Format Error operation with data of type transmit operation.
 */
TEST(Fmi3LsBusFormatError, transmit)
{
	CheckFormatErrorOperation(CanTransmit);
}

/**
 * \brief Test for the Format Error operation with data of type fd transmit operation.
 */
TEST(Fmi3LsBusFormatError, fdTransmit)
{
	CheckFormatErrorOperation(CanFdTransmit);
}

/**
 * \brief Test for the Format Error operation with data of type xl transmit operation.
 */
TEST(Fmi3LsBusFormatError, xlTransmit)
{
	CheckFormatErrorOperation(CanXlTransmit);
}

/**
 * \brief Test for the Format Error operation with data of type confirm operation.
 */
TEST(Fmi3LsBusFormatError, confirm)
{
	CheckFormatErrorOperation(Confirm);
}

/**
 * \brief Test for the Format Error operation with data of type configuration baudrate operation.
 */
TEST(Fmi3LsBusFormatError, configurationBaudrate)
{
	CheckFormatErrorOperation(ConfigurationBaudrate);
}

/**
 * \brief Test for the Format Error operation with data of type configuration fd baudrate operation.
 */
TEST(Fmi3LsBusFormatError, configurationFdBaudrate)
{
	CheckFormatErrorOperation(ConfigurationFdBaudrate);
}

/**
 * \brief Test for the Format Error operation with data of type configuration xl baudrate operation.
 */
TEST(Fmi3LsBusFormatError, configurationXlBaudrate)
{
	CheckFormatErrorOperation(ConfigurationXlBaudrate);
}

/**
 * \brief Test for the Format Error operation with data of type configuration arbitration lost behavior operation.
 */
TEST(Fmi3LsBusFormatError, configurationArbitrationLostBehavior)
{
	CheckFormatErrorOperation(ConfigurationArbitrationLostBehavior);
}

/**
 * \brief Test for the Format Error operation with data of type arbitration lost operation.
 */
TEST(Fmi3LsBusFormatError, arbitrationLost)
{
	CheckFormatErrorOperation(ArbitrationLost);
}

/**
 * \brief Test for the Format Error operation with data of type bus error operation.
 */
TEST(Fmi3LsBusFormatError, busError)
{
	CheckFormatErrorOperation(BusError);
}

/**
 * \brief Test for the Format Error operation with data of type status operation.
 */
TEST(Fmi3LsBusFormatError, status)
{
	CheckFormatErrorOperation(Status);
}

/**
 * \brief Test for the Format Error operation with data of type wakeup operation.
 */
TEST(Fmi3LsBusFormatError, wakeUp)
{
	CheckFormatErrorOperation(Wakeup);
}

/**
 * \brief Test for the Format Error operation with data that is too big.
 */
TEST(Fmi3LsBusFormatError, sizeError)
{
	CheckDataSizeError(FormatError);
}

/**
 * \brief Test for combination of all operations with biggest valid values.
 */
TEST(Fmi3LsBusCombinationTest, maxValues) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusCanOperationCanTransmit* canTransmitOperation;
	fmi3LsBusCanOperationCanFdTransmit* canFdTransmitOperation;
	fmi3LsBusCanOperationCanXlTransmit* canXlTransmitOperation;
	fmi3LsBusCanOperationConfirm* canConfirmOperation;
	fmi3LsBusCanOperationArbitrationLost* canArbitrationLostOperation;
	fmi3LsBusCanOperationBusError* canBusErrorOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationBaudrateOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationFdBaudrateOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationXlBaudrateOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationArbitrationLostBehaviorOperation;
	fmi3LsBusCanOperationStatus* canStatusOperation;


	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&firstBufferInfo, UINT32_MAX, UINT8_MAX, UINT8_MAX, sizeof(data), data);
	FMI3_LS_BUS_CAN_CREATE_OP_CAN_FD_TRANSMIT(&firstBufferInfo, UINT32_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, sizeof(data), data);
	FMI3_LS_BUS_CAN_CREATE_OP_CAN_XL_TRANSMIT(&firstBufferInfo, UINT32_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT32_MAX, sizeof(data), data);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIRM(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_ARBITRATION_LOST(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_BUS_ERROR(&firstBufferInfo, 0, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, 3);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_BAUDRATE(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_FD_BAUDRATE(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_XL_BAUDRATE(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_ARBITRATION_LOST_BEHAVIOR(&firstBufferInfo, FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);
	FMI3_LS_BUS_CAN_CREATE_OP_STATUS(&firstBufferInfo, FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE);
	FMI3_LS_BUS_CAN_CREATE_OP_WAKEUP(&firstBufferInfo);
	FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&firstBufferInfo, UINT32_MAX, UINT8_MAX, UINT8_MAX, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT);
	canTransmitOperation = (fmi3LsBusCanOperationCanTransmit*)operationHeader;
	EXPECT_EQ(canTransmitOperation->id, UINT32_MAX);
	EXPECT_EQ(canTransmitOperation->ide, UINT8_MAX);
	EXPECT_EQ(canTransmitOperation->rtr, UINT8_MAX);
	EXPECT_EQ(canTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canFdTransmitOperation = (fmi3LsBusCanOperationCanFdTransmit*)operationHeader;
	EXPECT_EQ(canFdTransmitOperation->id, UINT32_MAX);
	EXPECT_EQ(canFdTransmitOperation->ide, UINT8_MAX);
	EXPECT_EQ(canFdTransmitOperation->brs, UINT8_MAX);
	EXPECT_EQ(canFdTransmitOperation->esi, UINT8_MAX);
	EXPECT_EQ(canFdTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canFdTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canXlTransmitOperation = (fmi3LsBusCanOperationCanXlTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_CANXL_TRANSMIT);
	EXPECT_EQ(canXlTransmitOperation->id, UINT32_MAX);
	EXPECT_EQ(canXlTransmitOperation->ide, UINT8_MAX);
	EXPECT_EQ(canXlTransmitOperation->sec, UINT8_MAX);
	EXPECT_EQ(canXlTransmitOperation->sdt, UINT8_MAX);
	EXPECT_EQ(canXlTransmitOperation->vcid, UINT8_MAX);
	EXPECT_EQ(canXlTransmitOperation->af, UINT32_MAX);
	EXPECT_EQ(canXlTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canXlTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfirmOperation = (fmi3LsBusCanOperationConfirm*)operationHeader;
	EXPECT_EQ(canConfirmOperation->id, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canArbitrationLostOperation = (fmi3LsBusCanOperationArbitrationLost*)operationHeader;
	EXPECT_EQ(canArbitrationLostOperation->id, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canBusErrorOperation = (fmi3LsBusCanOperationBusError*)operationHeader;
	EXPECT_EQ(canBusErrorOperation->id, 0);
	EXPECT_EQ(canBusErrorOperation->errorCode, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR);
	EXPECT_EQ(canBusErrorOperation->errorFlag, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationBaudrateOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationBaudrateOperation->baudrate, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationFdBaudrateOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationFdBaudrateOperation->baudrate, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationXlBaudrateOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationXlBaudrateOperation->baudrate, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationArbitrationLostBehaviorOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationArbitrationLostBehaviorOperation->arbitrationLostBehavior, FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canStatusOperation = (fmi3LsBusCanOperationStatus*)operationHeader;
	EXPECT_EQ(canStatusOperation->status, FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_WAKEUP);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT);
	canTransmitOperation = (fmi3LsBusCanOperationCanTransmit*)operationHeader;
	EXPECT_EQ(canTransmitOperation->id, UINT32_MAX);
	EXPECT_EQ(canTransmitOperation->ide, UINT8_MAX);
	EXPECT_EQ(canTransmitOperation->rtr, UINT8_MAX);
	EXPECT_EQ(canTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canTransmitOperation->data[i], data[i]);
	}
}

/**
 * \brief Test for combination of all operations with a mix of biggest valid values and values that are too big.
 */
TEST(Fmi3LsBusCombinationTest, maxAndWrongValues) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];
	fmi3LsBusOperationHeader* operationHeader;
	fmi3LsBusCanOperationCanTransmit* canTransmitOperation;
	fmi3LsBusCanOperationCanFdTransmit* canFdTransmitOperation;
	fmi3LsBusCanOperationCanXlTransmit* canXlTransmitOperation;
	fmi3LsBusCanOperationConfirm* canConfirmOperation;
	fmi3LsBusCanOperationArbitrationLost* canArbitrationLostOperation;
	fmi3LsBusCanOperationBusError* canBusErrorOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationBaudrateOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationFdBaudrateOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationXlBaudrateOperation;
	fmi3LsBusCanOperationConfiguration* canConfigurationArbitrationLostBehaviorOperation;
	fmi3LsBusCanOperationStatus* canStatusOperation;


	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&firstBufferInfo, WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, sizeof(data), data);
	FMI3_LS_BUS_CAN_CREATE_OP_CAN_FD_TRANSMIT(&firstBufferInfo, UINT32_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX, sizeof(data), data);
	FMI3_LS_BUS_CAN_CREATE_OP_CAN_XL_TRANSMIT(&firstBufferInfo, WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT8, WRONG_U_INT32, sizeof(data), data);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIRM(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_ARBITRATION_LOST(&firstBufferInfo, WRONG_U_INT32);
	FMI3_LS_BUS_CAN_CREATE_OP_BUS_ERROR(&firstBufferInfo, UINT32_MAX, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG, 3);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_BAUDRATE(&firstBufferInfo, WRONG_U_INT32);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_FD_BAUDRATE(&firstBufferInfo, UINT32_MAX);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_CAN_XL_BAUDRATE(&firstBufferInfo, WRONG_U_INT32);
	FMI3_LS_BUS_CAN_CREATE_OP_CONFIGURATION_ARBITRATION_LOST_BEHAVIOR(&firstBufferInfo, FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);
	FMI3_LS_BUS_CAN_CREATE_OP_STATUS(&firstBufferInfo, FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE);
	FMI3_LS_BUS_CAN_CREATE_OP_WAKEUP(&firstBufferInfo);
	FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&firstBufferInfo, WRONG_U_INT32, WRONG_U_INT8, WRONG_U_INT8, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT);
	canTransmitOperation = (fmi3LsBusCanOperationCanTransmit*)operationHeader;
	EXPECT_EQ(canTransmitOperation->id, 0);
	EXPECT_EQ(canTransmitOperation->ide, 0);
	EXPECT_EQ(canTransmitOperation->rtr, 0);
	EXPECT_EQ(canTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canFdTransmitOperation = (fmi3LsBusCanOperationCanFdTransmit*)operationHeader;
	EXPECT_EQ(canFdTransmitOperation->id, UINT32_MAX);
	EXPECT_EQ(canFdTransmitOperation->ide, UINT8_MAX);
	EXPECT_EQ(canFdTransmitOperation->brs, UINT8_MAX);
	EXPECT_EQ(canFdTransmitOperation->esi, UINT8_MAX);
	EXPECT_EQ(canFdTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canFdTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canXlTransmitOperation = (fmi3LsBusCanOperationCanXlTransmit*)operationHeader;
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_CANXL_TRANSMIT);
	EXPECT_EQ(canXlTransmitOperation->id, 0);
	EXPECT_EQ(canXlTransmitOperation->ide, 0);
	EXPECT_EQ(canXlTransmitOperation->sec, 0);
	EXPECT_EQ(canXlTransmitOperation->sdt, 0);
	EXPECT_EQ(canXlTransmitOperation->af, 0);
	EXPECT_EQ(canXlTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canXlTransmitOperation->data[i], data[i]);
	}

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfirmOperation = (fmi3LsBusCanOperationConfirm*)operationHeader;
	EXPECT_EQ(canConfirmOperation->id, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canArbitrationLostOperation = (fmi3LsBusCanOperationArbitrationLost*)operationHeader;
	EXPECT_EQ(canArbitrationLostOperation->id, 0);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canBusErrorOperation = (fmi3LsBusCanOperationBusError*)operationHeader;
	EXPECT_EQ(canBusErrorOperation->id, UINT32_MAX);
	EXPECT_EQ(canBusErrorOperation->errorCode, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_CODE_BIT_ERROR);
	EXPECT_EQ(canBusErrorOperation->errorFlag, FMI3_LS_BUS_CAN_BUSERROR_PARAM_ERROR_FLAG_PRIMARY_ERROR_FLAG);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationBaudrateOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationBaudrateOperation->baudrate, 0);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationFdBaudrateOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationFdBaudrateOperation->baudrate, UINT32_MAX);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationXlBaudrateOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationXlBaudrateOperation->baudrate, 0);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canConfigurationArbitrationLostBehaviorOperation = (fmi3LsBusCanOperationConfiguration*)operationHeader;
	EXPECT_EQ(canConfigurationArbitrationLostBehaviorOperation->arbitrationLostBehavior, FMI3_LS_BUS_CAN_CONFIG_PARAM_ARBITRATION_LOST_BEHAVIOR_BUFFER_AND_RETRANSMIT);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	canStatusOperation = (fmi3LsBusCanOperationStatus*)operationHeader;
	EXPECT_EQ(canStatusOperation->status, FMI3_LS_BUS_CAN_STATUS_PARAM_STATUS_KIND_ERROR_ACTIVE);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_WAKEUP);

	FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);
	EXPECT_EQ(operationHeader->opCode, FMI3_LS_BUS_CAN_OP_CAN_TRANSMIT);
	canTransmitOperation = (fmi3LsBusCanOperationCanTransmit*)operationHeader;
	EXPECT_EQ(canTransmitOperation->id, 0);
	EXPECT_EQ(canTransmitOperation->ide, 0);
	EXPECT_EQ(canTransmitOperation->rtr, 0);
	EXPECT_EQ(canTransmitOperation->dataLength, sizeof(data));
	for (int i = 0; i < sizeof(data); i++)
	{
		EXPECT_EQ(canTransmitOperation->data[i], data[i]);
	}
}

/**
 * \brief Test for resetting a buffer.
 */
TEST(Fmi3LsBusCombinationTest, resetBuffer) {

	fmi3LsBusUtilBufferInfo firstBufferInfo;
	fmi3LsBusUtilBufferInfo secondBufferInfo;
	fmi3UInt8 txData[2048];
	fmi3UInt8 rxData[2048];

	FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
	FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

	fmi3UInt8 data[] = { 'A', 'B', 'C', 'D', 'A', 'B', 'C', 'D' };

	FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT(&firstBufferInfo, 0, 0, 0, sizeof(data), data);

	FMI3_LS_BUS_CAN_CREATE_OP_CAN_FD_TRANSMIT(&firstBufferInfo, 0, 0, 0, 0, sizeof(data), data);

	FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

	FMI3_LS_BUS_BUFFER_INFO_RESET(&firstBufferInfo);
	EXPECT_EQ(firstBufferInfo.readPos, firstBufferInfo.writePos);

	FMI3_LS_BUS_BUFFER_INFO_RESET(&secondBufferInfo);
	EXPECT_EQ(secondBufferInfo.readPos, secondBufferInfo.writePos);
}
