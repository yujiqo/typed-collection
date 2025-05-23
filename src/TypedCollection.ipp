#include <vector>
#include <memory>
#include <type_traits>

#include "../headers/TypedCollection.hpp"

using namespace tc;

template<Copyable T>
TypedCollection<T>::TypedCollection(TypedCollection<T>&& other) : container(std::move(this->container)) {};

template<Copyable T>
TypedCollection<T>::TypedCollection(const TypedCollection<T>& other) {
    std::vector<std::shared_ptr<T>> vec;

    for (auto& item : other.container) {
        vec.push_back(std::make_shared(*item));
    }

    this->container = std::move(vec);
}

template<Copyable T>
void TypedCollection<T>::add(const T& item) {
    this->container.push_back(std::make_shared<T>(item));
}

template<Copyable T>
template<typename Func>
void TypedCollection<T>::forEach(Func func) {
    for (auto& item : this->container) {
        if constexpr (std::is_integral_v<T>) {
            func(std::make_shared<T>(*item * 2));
        } else {
            func(item);
        }
    }
}

template<Copyable T>
size_t TypedCollection<T>::count() const {
    return this->container.size();
}
