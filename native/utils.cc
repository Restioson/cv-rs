#include "utils.h"

void vec_rect_cxx_to_c(const std::vector<cv::Rect>& cxx_vec_rect, VecRect* vr) {
    size_t num = cxx_vec_rect.size();
    vr->size = num;
    vr->array = (Rect*) malloc(num * sizeof(Rect));
    for (size_t i = 0; i < num; i++) {
        vr->array[i].x = cxx_vec_rect[i].x;
        vr->array[i].y = cxx_vec_rect[i].y;
        vr->array[i].width = cxx_vec_rect[i].width;
        vr->array[i].height = cxx_vec_rect[i].height;
    }
}

void vec_double_cxx_to_c(const std::vector<double>& cxx_vec_double,
                         VecDouble* vd) {
    size_t num = cxx_vec_double.size();
    vd->size = num;
    vd->array = (double*) malloc(num * sizeof(double));
    ::memcpy(vd->array, cxx_vec_double.data(), num * sizeof(double));
}
