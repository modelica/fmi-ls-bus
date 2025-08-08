#include "fmi3LsBusEthernet.h"
#include "fmi3LsBusUtil.h"
#include "fmi3LsBusUtilEthernet.h"
#include <iostream>


/**
 * \brief Values that cause an overflow for the tested datatype.
 */
#define WRONG_U_INT8 256
#define WRONG_U_INT16 65536
#define WRONG_U_INT32 0x100000000

 /**
  * \brief Enum of the available operations by name.
  */
enum Operation { Transmit, Confirm, ConfigurationSupportedPhyTypes, BusError, Wakeup, FormatError };

/**
 * \brief Checks if the CAN Transmit operation is created correctly by the corresponding macro.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] StartDelimiter
 *     The start frame (SFD) or start mPacket (SMD) delimiter  Always set to 0xD5 for ordinary Ethernet frames when not using preemption/fragmentation (\ref fmi3LsBusEthernetStartDelimiter).
 * \param[in] FragmentCounter
 *     Fragment counter of the continuation mPacket  Must be set to 0, if this is not a continuation mPacket (\ref fmi3LsBusEthernetMPacketFragmentCounter).
 * \param[in] LastFragment
 *     Indicates whether this is the last fragment of a fragmented Ethernet frame  Must be set to `TRUE` if this is a full Ethernet frame (\ref fmi3LsBusBoolean).
 * \param[in] DestinationAddress
 *     The destination address of the frame  Only applicable if this is a full Ethernet frame or the first fragment of an Ethernet frame (pointer of \ref fmi3LsBusEthernetMacAddressOctet).
 * \param[in] SourceAddress
 *     The destination address of the frame  Only applicable if this is a full Ethernet frame or the first fragment of an Ethernet frame (pointer of \ref fmi3LsBusEthernetMacAddressOctet).
 * \param[in] EtherTypeOrLength
 *     Indicates the type of Ethernet frame (Ethernet II), the TPID (802.1Q) or frame length (802.3) (\ref fmi3LsBusEthernetTypeOrLength).
 * \param[in] DataLength
 *     The length of the data of this Ethernet frame or mPacket  Note that this does not correspond to a field in the Ethernet frame (\ref fmi3LsBusEthernetDataLength).
 * \param[in] Data
 *     The payload data of the Ethernet frame or mPacket (pointer of \ref fmi3LsBusEthernetData).
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckEthernetTransmitOperation(int startDelimiter, int fragmentCounter, int lastFragment, unsigned char destinationAddress[6], unsigned char sourceAddress[6], int typeOrLength, uint32_t dataSize, fmi3UInt8 data[], bool correctData);

/**
 * \brief Checks if the Confirm operation is created correctly by the corresponding macro.
 */
void CheckConfirmOperation();

/**
 * \brief Checks if the WakeUp operation is created correctly by the corresponding macro.
 */
void CheckWakeupOperation();

/**
 * \brief Checks if the Bus Error operation is created correctly by the corresponding macro.
 *
 * \param[in] errorCode   The errorCode of the Bus Error operation.
 * \param[in] isSender    The attribute 'Is Sender' of the Bus Error operation.
 * \param[in] correctData Indicator if the method checks for a match of provided and created values or for an overflow of values.
 */
void CheckBusErrorOperation(int errorCode, fmi3UInt8 isSender, bool correctData);

/**
 * \brief Checks if the Format Error operation is created correctly by the corresponding macro.
 *
 * \param[in] operationType  The type of operation of the Format Error operation.
 */
void CheckFormatErrorOperation(Operation operationType);

/**
 * \brief Checks if the corresponding macro returns fmi3False if the data for creation is too big.
 *
 * \param[in] operation  The type of operation to be checked.
 */
void CheckDataSizeError(Operation operation);