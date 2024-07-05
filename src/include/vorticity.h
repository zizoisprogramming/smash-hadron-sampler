#include <array>
#include <cstddef>
#include <memory>
#include <optional>

#include "gen.h"

class Vorticity {
 public:
  // default constructor nulls all vorticity components
  Vorticity() : vorticity_({0.0}) {}

  // access the component i of the vorticity tensor as linear array
  double& operator[](size_t index) { return vorticity_[index]; }

  // const overload of the [] operator
  const double& operator[](size_t index) const { return vorticity_[index]; }

  // Set vorticity_ to a new array
  void set_vorticity(const std::array<double, 16>& new_vorticity) {
    vorticity_ = new_vorticity;
  }

  // Get the vorticity tensor as a 1D array
  std::array<double, 16> get_vorticity() const { return vorticity_; }

  // Check that the vorticity file exists.
  static void ensure_vorticity_file_exists_and_contains_16_values();

  // given the complete freezeout surface, this function sets the vorticity
  // tensor in all surface cells from the vorticity file
  static void set_vorticity_in_all_surface_cells(element* surf, int N);

  // return a component of the vorticity tensor as a 4x4 matrix
  double at(int i, int j) const { return vorticity_[i * 4 + j]; }

 private:
  std::array<double, 16> vorticity_;
};