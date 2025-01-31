/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <INTEGER.h>

asn_random_fill_result_t
INTEGER_random_fill(const asn_TYPE_descriptor_t *td, void **sptr,
                    const asn_encoding_constraints_t *constraints,
                    size_t max_length) {
    const asn_INTEGER_specifics_t *specs =
        (const asn_INTEGER_specifics_t *)td->specifics;
    asn_random_fill_result_t result_ok = {ARFILL_OK, 1};
    asn_random_fill_result_t result_failed = {ARFILL_FAILED, 0};
    asn_random_fill_result_t result_skipped = {ARFILL_SKIPPED, 0};
    INTEGER_t *st = *sptr;
    const asn_INTEGER_enum_map_t *emap;
    size_t emap_len;
    intmax_t value;
    int find_inside_map;

    if(max_length == 0) return result_skipped;

    if(st == NULL) {
        st = (INTEGER_t *)CALLOC(1, sizeof(*st));
        if(st == NULL) {
            return result_failed;
        }
    }

    if(specs) {
        emap = specs->value2enum;
        emap_len = specs->map_count;
        if(specs->strict_enumeration) {
            find_inside_map = emap_len > 0;
        } else {
            find_inside_map = emap_len ? asn_random_between(0, 1) : 0;
        }
    } else {
        emap = 0;
        emap_len = 0;
        find_inside_map = 0;
    }

    if(find_inside_map) {
        assert(emap_len > 0);
        value = emap[asn_random_between(0, emap_len - 1)].nat_value;
    } else {
        static const long variants[] = {
            -65536, -65535, -65534, -32769, -32768, -32767, -16385, -16384,
            -16383, -257,   -256,   -255,   -254,   -129,   -128,   -127,
            -126,   -1,     0,      1,      126,    127,    128,    129,
            254,    255,    256,    257,    16383,  16384,  16385,  32767,
            32768,  32769,  65534,  65535,  65536,  65537};
        if(specs && specs->field_unsigned) {
            assert(variants[18] == 0);
            value = variants[asn_random_between(
                18, sizeof(variants) / sizeof(variants[0]) - 1)];
        } else {
            value = variants[asn_random_between(
                0, sizeof(variants) / sizeof(variants[0]) - 1)];
        }

        if(!constraints) constraints = &td->encoding_constraints;
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
        const asn_per_constraints_t *ct;

        ct = constraints ? constraints->per_constraints : 0;
        if(ct && (ct->value.flags & APC_CONSTRAINED)) {
            if(value < ct->value.lower_bound || value > ct->value.upper_bound) {
                value = asn_random_between(ct->value.lower_bound,
                                           ct->value.upper_bound);
            }
        }
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
    }

    if(asn_imax2INTEGER(st, value)) {
        if(st == *sptr) {
            ASN_STRUCT_RESET(*td, st);
        } else {
            ASN_STRUCT_FREE(*td, st);
        }
        return result_failed;
    } else {
        *sptr = st;
        result_ok.length = st->size;
        return result_ok;
    }
}
