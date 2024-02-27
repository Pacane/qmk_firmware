#include "introspection.h"

#ifdef HOMEROW_UNILATERAL
static uint16_t    next_keycode;
static keyrecord_t next_record;
#endif

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef HOMEROW_UNILATERAL
    if (record->event.pressed) {
        // Cache current input for on-going mod-tap decisions
        next_keycode = keycode;
        next_record  = *record;
    }
#endif
    return true;
}
#ifdef HOMEROW_UNILATERAL
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    if (IS_UNILATERAL(record, next_record)) {
        // Set the tap keycode and send the pressed event
        record->keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        process_record(record);
        // Release the tap keycode and send the event
        record->event.pressed = false;
        process_record(record);
    }
    return false;
}
#endif


#ifdef HOMEROW_UNILATERAL
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Hold modifier with a nested bilateral tap on the opposite hand
    return IS_BILATERAL(record, next_record);
}
#endif
