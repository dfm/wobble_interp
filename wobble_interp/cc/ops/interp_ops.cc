#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"

using namespace tensorflow;

REGISTER_OP("Interp")
  .Attr("T: {float, double}")
  .Input("t: T")
  .Input("x: T")
  .Input("y: T")
  .Output("v: T")
  .Output("inds: int32")
  .SetShapeFn([](shape_inference::InferenceContext* c) {
    shape_inference::ShapeHandle t, x, y;
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(0), 1, &t));
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(1), 1, &x));
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(2), 1, &y));

    TF_RETURN_IF_ERROR(c->Merge(x, y, &x));

    TF_RETURN_IF_ERROR(c->Subshape(t, 0, -1, &t));
    TF_RETURN_IF_ERROR(c->Subshape(x, 0, -1, &x));
    TF_RETURN_IF_ERROR(c->Merge(t, x, &t));

    c->set_output(0, c->input(0));
    c->set_output(1, c->input(0));
    return Status::OK();
  });

REGISTER_OP("InterpRev")
  .Attr("T: {float, double}")
  .Input("t: T")
  .Input("x: T")
  .Input("y: T")
  .Input("inds: int32")
  .Input("bv: T")
  .Output("bt: T")
  .Output("by: T")
  .SetShapeFn([](shape_inference::InferenceContext* c) {
    shape_inference::ShapeHandle t, x, y, inds, bv;
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(0), 1, &t));
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(1), 1, &x));
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(2), 1, &y));
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(3), 1, &inds));
    TF_RETURN_IF_ERROR(c->WithRankAtLeast(c->input(4), 1, &bv));

    TF_RETURN_IF_ERROR(c->Merge(x, y, &x));
    TF_RETURN_IF_ERROR(c->Merge(t, inds, &t));
    TF_RETURN_IF_ERROR(c->Merge(t, bv, &t));

    TF_RETURN_IF_ERROR(c->Subshape(t, 0, -1, &t));
    TF_RETURN_IF_ERROR(c->Subshape(x, 0, -1, &x));
    TF_RETURN_IF_ERROR(c->Merge(t, x, &t));

    c->set_output(0, c->input(0));
    c->set_output(1, c->input(1));
    return Status::OK();
  });
