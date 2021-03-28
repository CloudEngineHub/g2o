#pragma once

#include "g2o/core/base_vertex.h"
#include "g2opy.h"

namespace g2o {

template <int D, typename T>
void templatedBaseVertex(py::module& m, const std::string& suffix) {
  using CLS = BaseVertex<D, T>;

  py::class_<CLS, OptimizableGraph::Vertex, std::shared_ptr<CLS>>(m,
                                                                  ("BaseVertex" + suffix).c_str())

      //.def(py::init<>())
      //.def_readonly_static("dimension", &BaseVertex<D, T>::Dimension)   // lead to undefined
      // symbol error
      .def("hessian", (double& (BaseVertex<D, T>::*)(int, int)) & BaseVertex<D, T>::hessian, "i"_a,
           "j"_a)
      .def("hessian_determinant", &CLS::hessianDeterminant)
      //.def("hessian_data", &CLS::hessianData)                                                  //
      //-> double* .def("map_hessian_memory", &CLS::mapHessianMemory) // double* -> void
      //.def("copy_b", &CLS::copyB) // double* -> void

      .def("b", (double& (CLS::*)(int)) & CLS::b, "i"_a)
      //.def("b_data", &CLS::bData) // -> double*

      .def("clear_quadratic_form", &CLS::clearQuadraticForm)
      .def("solve_direct", &CLS::solveDirect)
      .def("b", (Eigen::Matrix<double, D, 1, Eigen::ColMajor> & (CLS::*)()) & CLS::b,
           py::return_value_policy::reference)
      //.def("A", (HessianBlockType& (CLS::*) ()) &CLS::A,
      //        py::return_value_policy::reference)

      .def("push", &CLS::push)
      .def("pop", &CLS::pop)
      .def("discard_top", &CLS::discardTop)
      .def("stack_size", &CLS::stackSize)  // -> int

      .def("estimate", &CLS::estimate, py::return_value_policy::reference)  // -> T&
      .def("set_estimate", &CLS::setEstimate, "et"_a)                       // T& -> void
      ;
}

void declareBaseVertex(py::module& m);

}  // end namespace g2o
