#pragma once

#include <memory>
namespace Gadgetron{ namespace Core {

    class Message {
    public:
        virtual ~Message(){};

    };

    template<class T> class TypedMessage : public Message {
    public:

        TypedMessage(T input) : data(std::make_unique<T>(input)) {

        }

        TypedMessage(std::unique_ptr<T>&& input_ptr) : data(std::move(input_ptr)) {

        }

        TypedMessage(TypedMessage&& other) : data(other.get_data()) {

        }

        std::unique_ptr<T>&& get_data(){
            return std::move(data);
        }
        virtual ~TypedMessage(){};


    protected:
        std::unique_ptr<T> data;

    };
} }