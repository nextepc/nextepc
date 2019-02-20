/*************************************************************************** 

    Copyright (C) 2019 NextEPC Inc. All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

***************************************************************************/


#ifndef __MME_SM_H__
#define __MME_SM_H__

#include "core_param.h"
#include "core_fsm.h"
#include "core_event.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void mme_state_initial(fsm_t *s, event_t *e);
void mme_state_final(fsm_t *s, event_t *e);
void mme_state_operational(fsm_t *s, event_t *e);
void mme_state_exception(fsm_t *s, event_t *e);

void s1ap_state_initial(fsm_t *s, event_t *e);
void s1ap_state_final(fsm_t *s, event_t *e);
void s1ap_state_operational(fsm_t *s, event_t *e);
void s1ap_state_exception(fsm_t *s, event_t *e);

void emm_state_initial(fsm_t *s, event_t *e);
void emm_state_final(fsm_t *s, event_t *e);
void emm_state_de_registered(fsm_t *s, event_t *e);
void emm_state_authentication(fsm_t *s, event_t *e);
void emm_state_security_mode(fsm_t *s, event_t *e);
void emm_state_initial_context_setup(fsm_t *s, event_t *e);
void emm_state_registered(fsm_t *s, event_t *e);
void emm_state_exception(fsm_t *s, event_t *e);

void esm_state_initial(fsm_t *s, event_t *e);
void esm_state_final(fsm_t *s, event_t *e);
void esm_state_inactive(fsm_t *s, event_t *e);
void esm_state_active(fsm_t *s, event_t *e);
void esm_state_pdn_will_disconnect(fsm_t *s, event_t *e);
void esm_state_pdn_did_disconnect(fsm_t *s, event_t *e);
void esm_state_bearer_deactivated(fsm_t *s, event_t *e);
void esm_state_exception(fsm_t *s, event_t *e);

#define mme_sm_print(__pe) \
    d_print("%s(): %s\n", __func__, mme_event_get_name(__pe))

#define mme_sm_trace(__l, __pe) \
    d_trace(__l, "%s(): %s\n", __func__, mme_event_get_name(__pe))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !__MME_SM_H__ */
