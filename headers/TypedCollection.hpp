#pragma once

#include <vector>
#include <memory>
#include <concepts>

namespace tc {
    template<typename T>
    concept Copyable = std::copyable<T>;

    template<Copyable T>
    class TypedCollection {
    private:
        std::vector<std::shared_ptr<T>> container;
    public:
        TypedCollection() = default;

        TypedCollection(TypedCollection&& other);

        TypedCollection(const TypedCollection& other);

        void add(const T& item);

        template<typename Func>
        void forEach(Func func);

        size_t count() const;
    };
};

#include "../src/TypedCollection.ipp"
