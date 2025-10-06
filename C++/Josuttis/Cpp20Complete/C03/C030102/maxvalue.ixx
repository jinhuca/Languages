export module maxvalue;
import std;

// concept for pointer-like objects:
export template <typename T>
concept PointerLike = requires(T a) {
    { *a } -> std::same_as<typename T::element_type&>;
    { a.operator->() } -> std::same_as<typename T::element_type*>;
};
