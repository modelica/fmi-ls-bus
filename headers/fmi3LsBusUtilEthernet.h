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
 * \brief Base page for section 28 auto-negotiation.
 *
 * This macro can be used to create an Ethernet 'Auto Negotatiation Base Page' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] Selector
 *     Selector field (5 bits for section 28) (\ref fmi3LsBusEthernetAutoNegotiationSelector).
 * \param[in] TechnologyAbility
 *     Technology ability (7 bits for section 28) (\ref fmi3LsBusEthernetAutoNegotiationTechnologyAbility).
 * \param[in] ExtendedNextPage
 *     Indicates the support for extended next pages  (1 bit for section 28) (\ref fmi3LsBusBoolean).
 * \param[in] RemoteFault
 *     Remote fault indicator  (1 bit for section 28) (\ref fmi3LsBusBoolean).
 * \param[in] Ack
 *     Acknowledgement  (1 bit for section 28)  Reserved  Must be `FALSE` (\ref fmi3LsBusBoolean).
 * \param[in] NextPage
 *     Indicates the presence of a next page  (1 bit for section 28) (\ref fmi3LsBusBoolean).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_AUTO_NEGOTATIATION_BASE_PAGE(BufferInfo,   \
        Selector,                                                                 \
        TechnologyAbility,                                                        \
        ExtendedNextPage,                                                         \
        RemoteFault,                                                              \
        Ack,                                                                      \
        NextPage                                                                  \
    ) do {                                                                        \
        fmi3LsBusEthernetOperationAutoNegotatiationBasePage _op;                  \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_AUTO_NEGOTATIATION_BASE_PAGE; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)                      \
            + sizeof(fmi3LsBusEthernetAutoNegotiationSelector)                    \
            + sizeof(fmi3LsBusEthernetAutoNegotiationTechnologyAbility)           \
            + sizeof(fmi3LsBusBoolean)                                            \
            + sizeof(fmi3LsBusBoolean)                                            \
            + sizeof(fmi3LsBusBoolean)                                            \
            + sizeof(fmi3LsBusBoolean);                                           \
                                                                                  \
        _op.selector = Selector;                                                  \
        _op.technologyAbility = TechnologyAbility;                                \
        _op.extendedNextPage = ExtendedNextPage;                                  \
        _op.remoteFault = RemoteFault;                                            \
        _op.ack = Ack;                                                            \
        _op.nextPage = NextPage;                                                  \
                                                                                  \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);          \
    } while (0)


/**
 * \brief Base page for section 98 auto-negotiation.
 *
 * This macro can be used to create an Ethernet 'Single Differential Pair Auto Negotatiation Base Page' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] Selector
 *     Selector field  (5 bits for section 98) (\ref fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationSelector).
 * \param[in] EchoedNonce
 *     Echoed nonce  (5 bits for section 98)  Reserved Must be zeros (\ref fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce).
 * \param[in] SymmetricPauseCapabilityIndication
 *     Symmetric Pause capability  (2 bits for section 98) Bit 0 (\ref fmi3LsBusBoolean).
 * \param[in] AsymmetricPauseCapabilityIndication
 *     Asymmetric Pause capability  (2 bits for section 98) Bit 1 (\ref fmi3LsBusBoolean).
 * \param[in] ForceMasterSlave
 *     Force master/slave  (1 bit for section 98) (\ref fmi3LsBusBoolean).
 * \param[in] RemoteFault
 *     Indicates a remote fault  (1 bit for section 98) (\ref fmi3LsBusBoolean).
 * \param[in] Ack
 *     Acknowledgement (1 bit for section 98)  Reserved  Must be `FALSE` (\ref fmi3LsBusBoolean).
 * \param[in] NextPage
 *     Indicates the presence of a next page  (1 bit for section 98) (\ref fmi3LsBusBoolean).
 * \param[in] TransmittedNonce
 *     Transmitted nonce  (5 bits for section 98) (\ref fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce).
 * \param[in] TechnologyAability
 *     Technology ability  (27 bits for section 98) (\ref fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationTechnologyAbility).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_SINGLE_DIFFERENTIAL_PAIR_AUTO_NEGOTATIATION_BASE_PAGE(BufferInfo,   \
        Selector,                                                                                          \
        EchoedNonce,                                                                                       \
        SymmetricPauseCapabilityIndication,                                                                \
        AsymmetricPauseCapabilityIndication,                                                               \
        ForceMasterSlave,                                                                                  \
        RemoteFault,                                                                                       \
        Ack,                                                                                               \
        NextPage,                                                                                          \
        TransmittedNonce,                                                                                  \
        TechnologyAability                                                                                 \
    ) do {                                                                                                 \
        fmi3LsBusEthernetOperationSingleDifferentialPairAutoNegotatiationBasePage _op;                     \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_SINGLE_DIFFERENTIAL_PAIR_AUTO_NEGOTATIATION_BASE_PAGE; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)                                               \
            + sizeof(fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationSelector)                       \
            + sizeof(fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce)                          \
            + sizeof(fmi3LsBusBoolean)                                                                     \
            + sizeof(fmi3LsBusBoolean)                                                                     \
            + sizeof(fmi3LsBusBoolean)                                                                     \
            + sizeof(fmi3LsBusBoolean)                                                                     \
            + sizeof(fmi3LsBusBoolean)                                                                     \
            + sizeof(fmi3LsBusBoolean)                                                                     \
            + sizeof(fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce)                          \
            + sizeof(fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationTechnologyAbility);             \
                                                                                                           \
        _op.selector = Selector;                                                                           \
        _op.echoedNonce = EchoedNonce;                                                                     \
        _op.symmetricPauseCapabilityIndication = SymmetricPauseCapabilityIndication;                       \
        _op.asymmetricPauseCapabilityIndication = AsymmetricPauseCapabilityIndication;                     \
        _op.forceMasterSlave = ForceMasterSlave;                                                           \
        _op.remoteFault = RemoteFault;                                                                     \
        _op.ack = Ack;                                                                                     \
        _op.nextPage = NextPage;                                                                           \
        _op.transmittedNonce = TransmittedNonce;                                                           \
        _op.technologyAability = TechnologyAability;                                                       \
                                                                                                           \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);                                   \
    } while (0)


/**
 * \brief Next page for section 28 or 98 auto-negotiation.
 *
 * This macro can be used to create an Ethernet 'Auto Negotiation Page' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] MessagePage
 *     Indicates whether this is a message page (\ref fmi3LsBusBoolean).
 * \param[in] ExtendedPage
 *     Indicates that this is an extended page (section 28)  Must always be `TRUE` when using section 98 auto-negotiation (\ref fmi3LsBusBoolean).
 * \param[in] MessageCode
 *     Message code field  (11 bits for section 28 message page) (11 bits for section 28 extended message page) ( 0 bits for section 28 unformatted page) ( 0 bits for section 28 extended unformatted page) (11 bits for section 98 message page) ( 0 bits for section 98 unformatted page) The unused upper bits must be set to zero (\ref fmi3LsBusEthernetAutoNegotiationMessageCode).
 * \param[in] UnformattedCode
 *     Unformatted code field  ( 0 bits for section 28 message page) (11 bits for section 28 unformatted page) (32 bits for section 28 extended message page) (43 bits for section 28 extended unformatted page) (32 bits for section 98 message page) (43 bits for section 98 unformatted page) The unused upper bits must be set to zero (\ref fmi3LsBusEthernetAutoNegotiationUnformattedCode).
 * \param[in] Toggle
 *     Toggle bit for synchronization  Reserved  Must be `FALSE` (\ref fmi3LsBusBoolean).
 * \param[in] Ack
 *     Acknowledgement  Reserved  Must be `FALSE` (\ref fmi3LsBusBoolean).
 * \param[in] Ack2
 *     Acknowledgement 2  Reserved  Must be `FALSE` (\ref fmi3LsBusBoolean).
 * \param[in] NextPage
 *     Indicates the presence of a next page (\ref fmi3LsBusBoolean).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_AUTO_NEGOTIATION_PAGE(BufferInfo,   \
        MessagePage,                                                       \
        ExtendedPage,                                                      \
        MessageCode,                                                       \
        UnformattedCode,                                                   \
        Toggle,                                                            \
        Ack,                                                               \
        Ack2,                                                              \
        NextPage                                                           \
    ) do {                                                                 \
        fmi3LsBusEthernetOperationAutoNegotiationPage _op;                 \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_AUTO_NEGOTIATION_PAGE; \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)               \
            + sizeof(fmi3LsBusBoolean)                                     \
            + sizeof(fmi3LsBusBoolean)                                     \
            + sizeof(fmi3LsBusEthernetAutoNegotiationMessageCode)          \
            + sizeof(fmi3LsBusEthernetAutoNegotiationUnformattedCode)      \
            + sizeof(fmi3LsBusBoolean)                                     \
            + sizeof(fmi3LsBusBoolean)                                     \
            + sizeof(fmi3LsBusBoolean)                                     \
            + sizeof(fmi3LsBusBoolean);                                    \
                                                                           \
        _op.messagePage = MessagePage;                                     \
        _op.extendedPage = ExtendedPage;                                   \
        _op.messageCode = MessageCode;                                     \
        _op.unformattedCode = UnformattedCode;                             \
        _op.toggle = Toggle;                                               \
        _op.ack = Ack;                                                     \
        _op.ack2 = Ack2;                                                   \
        _op.nextPage = NextPage;                                           \
                                                                           \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);   \
    } while (0)


/**
 * \brief Provides information to indicate link state.
 *
 * This macro can be used to create an Ethernet 'Link State Indication' operation.
 * The arguments are serialized according to the FMI-LS-BUS specification and written to the buffer described by the argument `BufferInfo`.
 * If the operation was submitted successfully, `BufferInfo->status` is set to `fmi3True`.
 * If there is not enough buffer space available, `BufferInfo->status` is set to `fmi3False`.
 *
 * \param[in] BufferInfo
 *     Pointer to \ref fmi3LsBusUtilBufferInfo.
 * \param[in] PhysicalMediumAttachment
 *     The currently used physical medium attachment as null-terminated string  Elements describing a PHY standardized by 8023 or an amendment must use the value described in the chapter "303212 aPhyType" of the standard  Otherwise, a vendor-defined value may be used  If auto-negotiation is enabled but has not yet been performed, the value "unknown" should be used (pointer of \ref fmi3LsBusEthernetPhyTypeCharacter).
 * \param[in] Heartbeat
 *     Indicates that the node is sending a regular normal link pulse or IDLE symbol (\ref fmi3LsBusBoolean).
 * \param[in] MasterSlaveMode
 *     Indicates whether the node is operating as `MASTER` or `SLAVE` (\ref fmi3LsBusEthernetMasterSlaveMode).
 */
#define FMI3_LS_BUS_ETHERNET_CREATE_OP_LINK_STATE_INDICATION(BufferInfo,    \
        PhysicalMediumAttachment,                                           \
        Heartbeat,                                                          \
        MasterSlaveMode                                                     \
    ) do {                                                                  \
        fmi3LsBusEthernetOperationLinkStateIndication _op;                  \
        _op.header.opCode = FMI3_LS_BUS_ETHERNET_OP_LINK_STATE_INDICATION;  \
        _op.header.length = sizeof(fmi3LsBusOperationHeader)                \
            + 64 * sizeof(fmi3LsBusEthernetPhyTypeCharacter)                \
            + sizeof(fmi3LsBusBoolean)                                      \
            + sizeof(fmi3LsBusEthernetMasterSlaveMode);                     \
                                                                            \
        memcpy(_op.physicalMediumAttachment, PhysicalMediumAttachment, 64); \
        _op.heartbeat = Heartbeat;                                          \
        _op.masterSlaveMode = MasterSlaveMode;                              \
                                                                            \
        FMI_LS_BUS_SUBMIT_OPERATION_NO_DATA_INTERNAL((BufferInfo), _op);    \
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