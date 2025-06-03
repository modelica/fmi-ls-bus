#ifndef fmi3LsBusUtilEthernet_h
#define fmi3LsBusUtilEthernet_h


#include "fmi3LsBusUtil.h"
#include "fmi3LsBusEthernet.h"


/**
 * \brief Indicates the transmission of an Ethernet frame or mPacket.
 *
 * This macro can be used to create an Ethernet 'Transmit' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
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
 *     Indicates the type of Ethernet frame (Ethernet II) or frame length (8023) (\ref fmi3LsBusEthernetEtherTypeOrLength).
 * \param[in] DataLength
 *     The length of the data of this Ethernet frame or mPacket  Note that this does not correspond to a field in the Ethernet frame (\ref fmi3LsBusEthernetDataLength).
 * \param[in] Data
 *     The payload data of the Ethernet frame or mPacket (pointer of \ref fmi3LsBusEthernetData).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_TRANSMIT(BufferInfo,                            \
        StartDelimiter,                                                                \
        FragmentCounter,                                                               \
        LastFragment,                                                                  \
        DestinationAddress,                                                            \
        SourceAddress,                                                                 \
        EtherTypeOrLength,                                                             \
        DataLength,                                                                    \
        Data                                                                           \
    ) do {                                                                             \
        fmi3LsBusEthernetOperationTransmit _op;                                        \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_TRANSMIT;                          \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)                           \
            + sizeof(fmi3LsBusEthernetStartDelimiter)                                  \
            + sizeof(fmi3LsBusEthernetMPacketFragmentCounter)                          \
            + sizeof(fmi3LsBusBoolean)                                                 \
            + 6 * sizeof(fmi3LsBusEthernetMacAddressOctet)                             \
            + 6 * sizeof(fmi3LsBusEthernetMacAddressOctet)                             \
            + sizeof(fmi3LsBusEthernetEtherTypeOrLength)                               \
            + sizeof(fmi3LsBusEthernetDataLength)                                      \
            + (DataLength);                                                            \
                                                                                       \
        _op.startDelimiter = StartDelimiter;                                           \
        _op.fragmentCounter = FragmentCounter;                                         \
        _op.lastFragment = LastFragment;                                               \
        memcpy(_op.destinationAddress, DestinationAddress, 6);                         \
        memcpy(_op.sourceAddress, SourceAddress, 6);                                   \
        _op.etherTypeOrLength = EtherTypeOrLength;                                     \
        _op.dataLength = DataLength;                                                   \
                                                                                       \
        FMI_LS_BUS_SUBMIT_OPERATION_INTERNAL((BufferInfo), _op, (DataLength), (Data)); \
    } while (0)


/**
 * \brief Indicates the successful transmission of an Ethernet frame.
 *
 * This macro can be used to create an Ethernet 'Confirm' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIRM(BufferInfo                \
    ) do {                                                               \
        fmi3LsBusEthernetOperationConfirm _op;                           \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_CONFIRM;             \
        _op.header.length = sizeof(fmi3LsBusOperationHeader);            \
                                                                         \
                                                                         \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


/**
 * \brief Indicates an error during the transmission of an Ethernet frame.
 *
 * This macro can be used to create an Ethernet 'Bus Error' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] ErrorCode
 *     Represents the specified bus error to simulate (\ref fmi3LsBusEthernetBusErrorCode).
 * \param[in] IsSender
 *     Indicates whether this bus error occurs in response to a transmission of this FMU (\ref fmi3LsBusBoolean).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_BUS_ERROR(BufferInfo,             \
        ErrorCode,                                                       \
        IsSender                                                         \
    ) do {                                                               \
        fmi3LsBusEthernetOperationBusError _op;                          \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_BUS_ERROR;           \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)             \
            + sizeof(fmi3LsBusEthernetBusErrorCode)                      \
            + sizeof(fmi3LsBusBoolean);                                  \
                                                                         \
        _op.errorCode = ErrorCode;                                       \
        _op.isSender = IsSender;                                         \
                                                                         \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


/**
 * \brief Provides information to configure the Ethernet bus.
 *
 * This macro can be used to create an Ethernet 'Configuration' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] MdiMode
 *     The configuration of the node's media-dependent interface (\ref fmi3LsBusEthernetMdiMode).
 * \param[in] NumberOfSupportedPhyTypes
 *     The number of characters in the list of supported PHY types (\ref fmi3LsBusEthernetDataLength).
 * \param[in] SupportedPhyTypes
 *     An array of zero-terminated strings describing PHY types supported by this Ethernet node  The first element in this list indicates the type of PHY used by this node  The list must have at least one element  Elements describing a PHY standardized by 8023 or an amendment must use the value described in the chapter "303212 aPhyType" of the standard  Otherwise, a vendor-defined value may be used (\ref fmi3LsBusEthernetPhyTypeCharacter).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_CONFIGURATION_SUPPORTED_PHY_TYPES(BufferInfo,        \
        MdiMode,                                                                            \
        NumberOfSupportedPhyTypes,                                                          \
        SupportedPhyTypes                                                                   \
    ) do {                                                                                  \
        fmi3LsBusEthernetOperationConfiguration _op;                                        \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_CONFIGURATION;                          \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)                                \
            + sizeof(fmi3LsBusEthernetConfigParameterType)                                  \
            + sizeof(fmi3LsBusEthernetConfigurationSupportedPhyTypes);                      \
                                                                                            \
        _op.parameterType = FMI3_LS_BUS_ETHERNET_CONFIG_PARAMETER_TYPE_SUPPORTED_PHY_TYPES; \
        _op.supportedPhyTypes.mdiMode = MdiMode;                                            \
        _op.supportedPhyTypes.numberOfSupportedPhyTypes = NumberOfSupportedPhyTypes;        \
        _op.supportedPhyTypes.supportedPhyTypes = SupportedPhyTypes;                        \
                                                                                            \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);                    \
    } while (0)


/**
 * \brief Indicates a wakeup.
 *
 * This macro can be used to create an Ethernet 'Wakeup' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_WAKEUP(BufferInfo                 \
    ) do {                                                               \
        fmi3LsBusEthernetOperationWakeup _op;                            \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_WAKEUP;              \
        _op.header.length = sizeof(fmi3LsBusOperationHeader);            \
                                                                         \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op); \
    } while (0)


#endif /* fmi3LsBusUtilEthernet_h */