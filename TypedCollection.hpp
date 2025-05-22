#pragma once

#include <vector>
#include <memory>
#include <concepts>
#include <type_traits>

namespace tc {
    template<typename T>
    concept Copyable = std::copyable<T>;

    template<Copyable T>
    class TypedCollection {
    private:
        std::vector<std::shared_ptr<T>> container;
    public:
        TypedCollection() = default;

        TypedCollection(TypedCollection&& other) {
            this->container = std::move(other.container);
        };

        TypedCollection(const TypedCollection& other) {
            this->container = other.container;
        };

        void add(const T& item) {
            this->container.push_back(std::make_shared<T>(item));
        };


        template<typename Func>
        void forEach(Func func) {
            for (auto& item : this->container) {
                if constexpr (std::is_integral_v<T>) {
                    func(std::make_shared<T>(*item * 2));
                } else {
                    func(item);
                }
            }
        };


        size_t count() const {
            return this->container.size();
        }
    };
}
