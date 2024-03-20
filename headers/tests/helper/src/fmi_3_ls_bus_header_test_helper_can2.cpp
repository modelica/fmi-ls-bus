#include "fmi_3_ls_bus_header_test_helper_can2.h"
#include <gtest/gtest.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#endif

	void CheckCanTransmitOperation2(long long int id, int ide, int rtr, fmi3UInt8 data[], bool correctData)
	{
		// Create data needed for creation.
		fmi3LsBusUtilBufferInfo firstBufferInfo;
		fmi3LsBusUtilBufferInfo secondBufferInfo;
		fmi3UInt8 txData[2048];
		fmi3UInt8 rxData[2048];

		fmi3LsBusOperationHeader* operationHeader;
		fmi3LsBusCanOperationCanTransmit2* operation;

		FMI3_LS_BUS_BUFFER_INFO_INIT(&firstBufferInfo, txData, sizeof(txData));
		FMI3_LS_BUS_BUFFER_INFO_INIT(&secondBufferInfo, rxData, sizeof(rxData));

		// Create operation.
		FMI3_LS_BUS_CAN_CREATE_OP_CAN_TRANSMIT2(&firstBufferInfo, id, ide, rtr, sizeof(data), data);

		// Write operation to a second buffer.
		FMI3_LS_BUS_BUFFER_WRITE(&secondBufferInfo, txData, sizeof(txData));

		// Read and check created method from second buffer.
		FMI3_LS_BUS_READ_NEXT_OPERATION(&secondBufferInfo, operationHeader);

		operation = (fmi3LsBusCanOperationCanTransmit2*)operationHeader;

		// Specify whether the created data are checked for correctness or an overflow.
		int multiplier = (correctData) ? 1 : 0;

		EXPECT_EQ(secondBufferInfo.status, fmi3True);

		EXPECT_EQ(operation->id, id * multiplier);
		EXPECT_EQ(operation->ide, ide * multiplier);
		EXPECT_EQ(operation->rtr, rtr * multiplier);
		EXPECT_EQ(operation->dataLength, sizeof(data));
		for (int i = 0; i < sizeof(data); i++)
		{
			EXPECT_EQ(operation->data[i], data[i]);
		}
	}
