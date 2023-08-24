
#include <iostream>
using std::cout;

#include <cstdlib>
using std::size_t;

#include <string>
using std::string;

#include <sstream>
using std::ostringstream;

#include <array>
#include<algorithm>

// alias = apelido
using value_type = int;

/// This function should return a string representation of the vector provided.
/*!
 * @param A The array we need to convert its content to a string from.
 * @param len The length of the input array.
 * @return A string representation for the array's content.
 */
template <size_t len>
std::string to_string(const std::array<value_type, len> &A) {
    std::ostringstream oss;

    oss <<"[ ";

    for(size_t i{0}; i< A.size();i++){
        oss<< A[i] << " ";
    }
    oss << "] ";

    return oss.str();
}

/*!
 * This function does a linear search in the array `A`, from index `l` to index
 * `r`, looking for the target `target`. Note that we are considering the closed
 * interval [l,r] over `A`.
 *
 * If target is found, the function return the index of the its first occurrence
 * in the array. Otherwise it returns the index just past the last element (i.e.
 * `r`+1).
 *
 * @param A The array where the search is done.
 * @param l The initial index that defines the searching space (range).
 * @param r The final index that defines the searching space (range).
 * @return The index of the first occurrence of `target`, or `r+1` otherwise.
 */

// This is the client code.
//implementar essa função postumo


template<size_t n>
size_t Bsearch(const std::array<value_type, n> &A, std::size_t l, size_t r, value_type target) {
    while (l <= r) {
        size_t meio = (l + r) / 2;
        if (A[meio] == target) {
            return meio;
        } else if (A[meio] < target) {
            l = meio + 1;
        } else {
            r = meio - 1;
        }
    }
    return r + 1; // Indica que o alvo não foi encontrado
}




int main() {
  // Search space.
  constexpr size_t array_len{10};
  std::array<value_type, array_len> v{2, 3, -5, 8, 10, 7, 6, -4, 1,-10 };

  // Print the array content to the standard output.
  std::cout << "Array V: " << to_string(v) << "\n";



  // This is an example of the C++ "ranged for"
  // We'll seach for each of the elements in `V` which, of course, must all be
  // found.
    value_type target{-5};



  std::sort(v.begin(), v.end());
  std::cout<< to_string(v);

  size_t idx = Bsearch(v, 1,array_len - 3, target);
  std::cout<<std::endl;
    // Check the search result and print the proper message.
    if (idx == array_len) {
      std::cout << "Target " << target << " not found!\n";
    } else {
      std::cout << "Found target " << target << " at position " << idx+1 << "\n";
    }
    return 0;
  }

  
