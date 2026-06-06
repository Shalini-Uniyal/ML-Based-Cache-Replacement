#ifndef _ML_PREDICT_H
#define _ML_PREDICT_H

#include <linux/mm.h>
#include <linux/mm_inline.h>
#include <linux/page-flags.h>

static inline int ml_predict(struct folio *folio)
{
    int reference_bit = folio_test_referenced(folio) ? 1 : 0;
    int dirty_bit = folio_test_dirty(folio) ? 1 : 0;

    unsigned long age = atomic_read(&folio->_mapcount);
    unsigned long access_count = folio_ref_count(folio);

    if (dirty_bit == 0) {
        if (reference_bit == 0) {
            if (age <= 3)
                return 0;
            else
                return 1;
        } else {
            if (access_count > 7269 && access_count <= 7621)
                return 1;
            else if (access_count > 9103)
                return 1;
            else
                return 0;
        }
    } else {
        if (access_count > 5161 && access_count <= 5473)
            return 1;
        else
            return 0;
    }
}

#endif