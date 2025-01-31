/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r17.3.0/36413-h30.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_S1AP_SourceNodeID_H_
#define	_S1AP_SourceNodeID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_SourceNodeID_PR {
	S1AP_SourceNodeID_PR_NOTHING,	/* No components present */
	S1AP_SourceNodeID_PR_sourceNgRanNode_ID,
	S1AP_SourceNodeID_PR_sourceNodeID_Extension
} S1AP_SourceNodeID_PR;

/* Forward declarations */
struct S1AP_SourceNgRanNode_ID;
struct S1AP_SourceNodeID_Extension;

/* S1AP_SourceNodeID */
typedef struct S1AP_SourceNodeID {
	S1AP_SourceNodeID_PR present;
	union S1AP_SourceNodeID_u {
		struct S1AP_SourceNgRanNode_ID	*sourceNgRanNode_ID;
		struct S1AP_SourceNodeID_Extension	*sourceNodeID_Extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_SourceNodeID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_SourceNodeID;
extern asn_CHOICE_specifics_t asn_SPC_S1AP_SourceNodeID_specs_1;
extern asn_TYPE_member_t asn_MBR_S1AP_SourceNodeID_1[2];
extern asn_per_constraints_t asn_PER_type_S1AP_SourceNodeID_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_SourceNodeID_H_ */
#include <asn_internal.h>
