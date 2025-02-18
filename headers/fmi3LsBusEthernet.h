#ifndef fmi3LsBusEthernet_h
#define fmi3LsBusEthernet_h

#include "fmi3LsBus.h"
#include "fmi3PlatformTypes.h"


/**
 * \defgroup FMI3_LS_BUS_ETHERNET_OPERATION_CODES Ethernet bus-specific operation codes
 * \brief Operation codes for Ethernet-specific bus operations.
 * \{
 */

/**
 * \brief FMI virtual bus operation of type 'Transmit'.
 *
 * Indicates the transmission of an Ethernet frame or mPacket.
 */
#define FMI3_LS_BUS_ETHERNET_OP_TRANSMIT ((fmi3LsBusOperationCode)0x10)

/**
 * \brief FMI virtual bus operation of type 'Confirm'.
 *
 * Indicates the successful transmission of an Ethernet frame.
 */
#define FMI3_LS_BUS_ETHERNET_OP_CONFIRM ((fmi3LsBusOperationCode)0x15)

/**
 * \brief FMI virtual bus operation of type 'Bus Error'.
 *
 * Indicates an error during the transmission of an Ethernet frame.
 */
#define FMI3_LS_BUS_ETHERNET_OP_BUS_ERROR ((fmi3LsBusOperationCode)0x16)

/**
 * \brief FMI virtual bus operation of type 'Configuration'.
 *
 * Provides information to configure the Ethernet bus.
 */
#define FMI3_LS_BUS_ETHERNET_OP_CONFIGURATION ((fmi3LsBusOperationCode)0x20)

/**
 * \brief FMI virtual bus operation of type 'Auto Negotatiation Base Page'.
 *
 * Base page for section 28 auto-negotiation.
 */
#define FMI3_LS_BUS_ETHERNET_OP_AUTO_NEGOTATIATION_BASE_PAGE ((fmi3LsBusOperationCode)0x30)

/**
 * \brief FMI virtual bus operation of type 'Single Differential Pair Auto Negotatiation Base Page'.
 *
 * Base page for section 98 auto-negotiation.
 */
#define FMI3_LS_BUS_ETHERNET_OP_SINGLE_DIFFERENTIAL_PAIR_AUTO_NEGOTATIATION_BASE_PAGE ((fmi3LsBusOperationCode)0x31)

/**
 * \brief FMI virtual bus operation of type 'Auto Negotiation Page'.
 *
 * Next page for section 28 or 98 auto-negotiation.
 */
#define FMI3_LS_BUS_ETHERNET_OP_AUTO_NEGOTIATION_PAGE ((fmi3LsBusOperationCode)0x32)

/**
 * \brief FMI virtual bus operation of type 'Link State Indication'.
 *
 * Provides information to indicate link state.
 */
#define FMI3_LS_BUS_ETHERNET_OP_LINK_STATE_INDICATION ((fmi3LsBusOperationCode)0x40)

/**
 * \brief FMI virtual bus operation of type 'Wakeup'.
 *
 * Indicates a wakeup.
 */
#define FMI3_LS_BUS_ETHERNET_OP_WAKEUP ((fmi3LsBusOperationCode)0x50)

/** \} */


/**
 * \defgroup FMI3_LS_BUS_ETHERNET_DATA_TYPES Ethernet-specific data types
 * \brief Data types used for Ethernet.
 * \{
 */

/**
 * \brief Data type representing an octet of the MAC address.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMacAddressOctet;

/**
 * \brief Data type representing the EtherType or frame length.
 */
typedef fmi3UInt16 fmi3LsBusEthernetEtherTypeOrLength;

/**
 * \brief Data type representing the Ethernet frame payload data.
 */
typedef fmi3UInt8 fmi3LsBusEthernetData;

/**
 * \brief Data type representing the Ethernet frame payload length.
 */
typedef fmi3UInt8 fmi3LsBusEthernetDataLength;

/**
 * \brief Data type representing a CRC checksum.
 */
typedef fmi3UInt32 fmi3LsBusEthernetCRC;

/**
 * \brief Data type representing an "Start frame delimiter" (SFD) or "Start mPacket delimiter" (SMD).
 */
typedef fmi3UInt8 fmi3LsBusEthernetStartDelimiter;

/**
 * \brief Data type representing the fragment counter of an mPacket.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMPacketFragmentCounter;

/**
 * \brief Data type representing the parameter configured with a configuration operation.
 */
typedef fmi3UInt8 fmi3LsBusEthernetConfigParameterType;

/**
 * \brief Indicates the supported Ethernet PHYs of this node.
 */
#define FMI3_LS_BUS_ETHERNET_CONFIG_PARAMETER_TYPE_SUPPORTED_PHY_TYPES ((fmi3LsBusEthernetConfigParameterType)0x0)

/**
 * \brief The length of the list of supported PHY types.
 */
typedef fmi3UInt16 fmi3LsBusEthernetPhyTypeLength;

/**
 * \brief Data type representing a character.
 */
typedef fmi3Char fmi3LsBusEthernetPhyTypeCharacter;

/**
 * \brief The 5-bit selector field transmitted in the auto-negotation process.
 */
typedef fmi3UInt8 fmi3LsBusEthernetAutoNegotiationSelector;

/**
 * \brief The 7-bit technology ability field transmitted in the auto-negotation process.
 */
typedef fmi3UInt32 fmi3LsBusEthernetAutoNegotiationTechnologyAbility;

/**
 * \brief The 11-bit message code in an auto-negotiation message page.
 */
typedef fmi3UInt16 fmi3LsBusEthernetAutoNegotiationMessageCode;

/**
 * \brief The 11 to 33-bit unformatted code in an auto-negotiation unformatted page.
 */
typedef fmi3UInt64 fmi3LsBusEthernetAutoNegotiationUnformattedCode;

/**
 * \brief The 5-bit selector field transmitted in the auto-negotation process for single differential-pair media.
 */
typedef fmi3UInt8 fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationSelector;

/**
 * \brief The 5-bit nonce transmitted in the auto-negotation process for single differential-pair media.
 */
typedef fmi3UInt8 fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce;

/**
 * \brief The 27-bit technology ability field transmitted in the auto-negotation process for single differential-pair media.
 */
typedef fmi3UInt32 fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationTechnologyAbility;

/**
 * \brief Indicates whether the node media-dependent interface of the node is wired in a crossover configuration.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMdiMode;

/**
 * \brief Not applicable
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_NONE ((fmi3LsBusEthernetMdiMode)0x0)
/**
 * \brief The MDI is wired in normal configuration.
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_MDI ((fmi3LsBusEthernetMdiMode)0x1)
/**
 * \brief The MDI is wired in crossover configuration.
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_MDI_X ((fmi3LsBusEthernetMdiMode)0x2)
/**
 * \brief The node supports auto MDI/MDI-X.
 */
#define FMI3_LS_BUS_ETHERNET_MDI_MODE_AUTO_MDI_X ((fmi3LsBusEthernetMdiMode)0x3)

/**
 * \brief Configuration data sent with 'Configuration' operation of type 'SUPPORTED_PHY_TYPES'. This configuration opeation serves to check the compatibility on the physical layer.
 */
typedef struct
{
    fmi3LsBusEthernetMdiMode mdiMode;  /**< The configuration of the node's media-dependent interface */
    fmi3LsBusEthernetDataLength numberOfSupportedPhyTypes;  /**< The number of characters in the list of supported PHY types */
    fmi3LsBusEthernetPhyTypeCharacter supportedPhyTypes;  /**< An array of zero-terminated strings describing PHY types supported by this Ethernet node  The first element in this list indicates the type of PHY used by this node  The list must have at least one element  Elements describing a PHY standardized by 8023 or an amendment must use the value described in the chapter "303212 aPhyType" of the standard  Otherwise, a vendor-defined value may be used */
} fmi3LsBusEthernetConfigurationSupportedPhyTypes;

/**
 * \brief Indicates whether the node is operating as Master or Slave, if applicable for the given PHY.
 */
typedef fmi3UInt8 fmi3LsBusEthernetMasterSlaveMode;

/**
 * \brief Not applicable.
 */
#define FMI3_LS_BUS_ETHERNET_MASTER_SLAVE_MODE_NONE ((fmi3LsBusEthernetMasterSlaveMode)0x0)
/**
 * \brief Node is operating as Master.
 */
#define FMI3_LS_BUS_ETHERNET_MASTER_SLAVE_MODE_MASTER ((fmi3LsBusEthernetMasterSlaveMode)0x1)
/**
 * \brief Node is operating as Slave.
 */
#define FMI3_LS_BUS_ETHERNET_MASTER_SLAVE_MODE_SLAVE ((fmi3LsBusEthernetMasterSlaveMode)0x2)

/**
 * \brief Indicates the type of a bus error.
 */
typedef fmi3UInt8 fmi3LsBusEthernetBusErrorCode;

/**
 * \brief Unknown error.
 */
#define FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_UNKNOWN ((fmi3LsBusEthernetBusErrorCode)0x0)
/**
 * \brief The medium is currently busy.
 */
#define FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_MEDIUM_BUSY ((fmi3LsBusEthernetBusErrorCode)0x1)
/**
 * \brief A frame collided during transmission.
 */
#define FMI3_LS_BUS_ETHERNET_BUS_ERROR_CODE_COLLISION ((fmi3LsBusEthernetBusErrorCode)0x2)

/** \} */

/**
 * \defgroup FMI3_LS_BUS_ETHERNET_OPERATION_TYPES Ethernet-specific operation types
 * \brief Operations used for Ethernet.
 * \{
 */

/**
 * \brief Indicates the transmission of an Ethernet frame or mPacket.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                          /**< Operation header */
    fmi3LsBusEthernetStartDelimiter startDelimiter;           /**< The start frame (SFD) or start mPacket (SMD) delimiter  Always set to 0xD5 for ordinary Ethernet frames when not using preemption/fragmentation */
    fmi3LsBusEthernetMPacketFragmentCounter fragmentCounter;  /**< Fragment counter of the continuation mPacket  Must be set to 0, if this is not a continuation mPacket */
    fmi3LsBusBoolean lastFragment;                            /**< Indicates whether this is the last fragment of a fragmented Ethernet frame  Must be set to `TRUE` if this is a full Ethernet frame */
    fmi3LsBusEthernetMacAddressOctet destinationAddress[6];   /**< The destination address of the frame  Only applicable if this is a full Ethernet frame or the first fragment of an Ethernet frame */
    fmi3LsBusEthernetMacAddressOctet sourceAddress[6];        /**< The destination address of the frame  Only applicable if this is a full Ethernet frame or the first fragment of an Ethernet frame */
    fmi3LsBusEthernetEtherTypeOrLength etherTypeOrLength;     /**< Indicates the type of Ethernet frame (Ethernet II) or frame length (8023) */
    fmi3LsBusEthernetDataLength dataLength;                   /**< The length of the data of this Ethernet frame or mPacket  Note that this does not correspond to a field in the Ethernet frame */
    fmi3LsBusEthernetData data[];                             /**< The payload data of the Ethernet frame or mPacket */
} fmi3LsBusEthernetOperationTransmit;

/**
 * \brief Indicates the successful transmission of an Ethernet frame.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
} fmi3LsBusEthernetOperationConfirm;

/**
 * \brief Indicates an error during the transmission of an Ethernet frame.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;          /**< Operation header */
    fmi3LsBusEthernetBusErrorCode errorCode;  /**< Represents the specified bus error to simulate */
    fmi3LsBusBoolean isSender;                /**< Indicates whether this bus error occurs in response to a transmission of this FMU */
} fmi3LsBusEthernetOperationBusError;

/**
 * \brief Provides information to configure the Ethernet bus.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                        /**< Operation header */
    fmi3LsBusEthernetConfigParameterType parameterType;                     /**< Defines the current configuration parameter */
    union
    {
        fmi3LsBusEthernetConfigurationSupportedPhyTypes supportedPhyTypes;  /**< Configuration data for parameter 'SUPPORTED_PHY_TYPES'. */
    };
} fmi3LsBusEthernetOperationConfiguration;

/**
 * \brief Base page for section 28 auto-negotiation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                      /**< Operation header */
    fmi3LsBusEthernetAutoNegotiationSelector selector;                    /**< Selector field (5 bits for section 28) */
    fmi3LsBusEthernetAutoNegotiationTechnologyAbility technologyAbility;  /**< Technology ability (7 bits for section 28) */
    fmi3LsBusBoolean extendedNextPage;                                    /**< Indicates the support for extended next pages  (1 bit for section 28) */
    fmi3LsBusBoolean remoteFault;                                         /**< Remote fault indicator  (1 bit for section 28) */
    fmi3LsBusBoolean ack;                                                 /**< Acknowledgement  (1 bit for section 28)  Reserved  Must be `FALSE` */
    fmi3LsBusBoolean nextPage;                                            /**< Indicates the presence of a next page  (1 bit for section 28) */
} fmi3LsBusEthernetOperationAutoNegotatiationBasePage;

/**
 * \brief Base page for section 98 auto-negotiation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                                             /**< Operation header */
    fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationSelector selector;                     /**< Selector field  (5 bits for section 98) */
    fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce echoedNonce;                     /**< Echoed nonce  (5 bits for section 98)  Reserved Must be zeros */
    fmi3LsBusBoolean symmetricPauseCapabilityIndication;                                         /**< Symmetric Pause capability  (2 bits for section 98) Bit 0 */
    fmi3LsBusBoolean asymmetricPauseCapabilityIndication;                                        /**< Asymmetric Pause capability  (2 bits for section 98) Bit 1 */
    fmi3LsBusBoolean forceMasterSlave;                                                           /**< Force master/slave  (1 bit for section 98) */
    fmi3LsBusBoolean remoteFault;                                                                /**< Indicates a remote fault  (1 bit for section 98) */
    fmi3LsBusBoolean ack;                                                                        /**< Acknowledgement (1 bit for section 98)  Reserved  Must be `FALSE` */
    fmi3LsBusBoolean nextPage;                                                                   /**< Indicates the presence of a next page  (1 bit for section 98) */
    fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationNonce transmittedNonce;                /**< Transmitted nonce  (5 bits for section 98) */
    fmi3LsBusEthernetSingleDifferentialPairAutoNegotiationTechnologyAbility technologyAability;  /**< Technology ability  (27 bits for section 98) */
} fmi3LsBusEthernetOperationSingleDifferentialPairAutoNegotatiationBasePage;

/**
 * \brief Next page for section 28 or 98 auto-negotiation.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                  /**< Operation header */
    fmi3LsBusBoolean messagePage;                                     /**< Indicates whether this is a message page */
    fmi3LsBusBoolean extendedPage;                                    /**< Indicates that this is an extended page (section 28)  Must always be `TRUE` when using section 98 auto-negotiation */
    fmi3LsBusEthernetAutoNegotiationMessageCode messageCode;          /**< Message code field  (11 bits for section 28 message page) (11 bits for section 28 extended message page) ( 0 bits for section 28 unformatted page) ( 0 bits for section 28 extended unformatted page) (11 bits for section 98 message page) ( 0 bits for section 98 unformatted page) The unused upper bits must be set to zero */
    fmi3LsBusEthernetAutoNegotiationUnformattedCode unformattedCode;  /**< Unformatted code field  ( 0 bits for section 28 message page) (11 bits for section 28 unformatted page) (32 bits for section 28 extended message page) (43 bits for section 28 extended unformatted page) (32 bits for section 98 message page) (43 bits for section 98 unformatted page) The unused upper bits must be set to zero */
    fmi3LsBusBoolean toggle;                                          /**< Toggle bit for synchronization  Reserved  Must be `FALSE` */
    fmi3LsBusBoolean ack;                                             /**< Acknowledgement  Reserved  Must be `FALSE` */
    fmi3LsBusBoolean ack2;                                            /**< Acknowledgement 2  Reserved  Must be `FALSE` */
    fmi3LsBusBoolean nextPage;                                        /**< Indicates the presence of a next page */
} fmi3LsBusEthernetOperationAutoNegotiationPage;

/**
 * \brief Provides information to indicate link state.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;                                 /**< Operation header */
    fmi3LsBusEthernetPhyTypeCharacter physicalMediumAttachment[64];  /**< The currently used physical medium attachment as null-terminated string  Elements describing a PHY standardized by 8023 or an amendment must use the value described in the chapter "303212 aPhyType" of the standard  Otherwise, a vendor-defined value may be used  If auto-negotiation is enabled but has not yet been performed, the value "unknown" should be used */
    fmi3LsBusBoolean heartbeat;                                      /**< Indicates that the node is sending a regular normal link pulse or IDLE symbol */
    fmi3LsBusEthernetMasterSlaveMode masterSlaveMode;                /**< Indicates whether the node is operating as `MASTER` or `SLAVE` */
} fmi3LsBusEthernetOperationLinkStateIndication;

/**
 * \brief Indicates a wakeup.
 */
typedef struct
{
    fmi3LsBusOperationHeader header;  /**< Operation header */
} fmi3LsBusEthernetOperationWakeup;

/** \} */


#endif /* fmi3LsBusEthernet_h */