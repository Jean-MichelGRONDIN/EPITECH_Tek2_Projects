/*
** EPITECH PROJECT, 2020
** bootstrap_OOP_nanotekspice_2019
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <functional>
#include <ctype.h>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true ,
        FALSE = false
    };

    enum PutsType {
        INPUT = 21,
        OUTPUT = 22,
        UNUSED = 23
    };

    enum PartsType {
        CHIPSET = 41,
        LINKS = 42
    };

    enum Componenttype {
        ANDC = 61,
        INPUTC = 62,
        OUTPUTC = 63,
        CLOCKC = 64,
        ORC = 65,
        XORC = 66,
        NANDC = 67,
        NORC = 68,
        XNORC = 69,
        C4001 = 70,
        C4011 = 71,
        C4030 = 72,
        C4071 = 73,
        C4081 = 74,
        NOTC = 75,
        C4069 = 76,
        TRUEC = 77,
        FALSEC = 78,
        C4013 = 79
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void compute() = 0;
            virtual void dump() const = 0;
    };

    class Cable;

    class Component : public IComponent {
        public:
            Component();
            virtual ~Component() override;
            void addLink(size_t put, Cable &link);
            virtual void compute();
            virtual void dump() const;
            Tristate getThisPutStatu(size_t n);
            void setThisPutStatu(size_t n, Tristate statu);
            std::string getName(void) const;
            void setName(std::string new_name);
            Componenttype getComponentType(void) const;
            virtual void print_compute();
            PutsType& getThisPutType(size_t n);
        protected:
            std::unordered_map<size_t, Cable&> _links;
            std::unordered_map<size_t, PutsType> _puts_types;
            std::unordered_map<size_t, Tristate> _puts;
            std::string _name;
            Componenttype _type;
    };

    class Cable {
        public:
            Cable();
            ~Cable();
            void setIn(Component *in, size_t in_nb);
            void setOut(Component *out, size_t out_nb);
            Component *getIn() const;
            Component *getOut() const;
            size_t getInNb() const;
            size_t getOutNb() const;
            void dumb() const;
        private:
            size_t _in_nb;
            Component *_in;
            size_t _out_nb;
            Component *_out;
    };

    class and_Comp : public Component {
        public:
            and_Comp(std::string name = "and_gate_by_jm");
            ~and_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatAndComp(const std::string &value);
    };

    class or_Comp : public Component {
        public:
            or_Comp(std::string name = "or_gate_by_jm");
            ~or_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatOrComp(const std::string &value);
    };

    class xor_Comp : public Component {
        public:
            xor_Comp(std::string name = "xor_gate_by_jm");
            ~xor_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatXorComp(const std::string &value);
    };

    class nand_Comp : public Component {
        public:
            nand_Comp(std::string name = "nand_gate_by_jm");
            ~nand_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatNandComp(const std::string &value);
    };

    class nor_Comp : public Component {
        public:
            nor_Comp(std::string name = "nor_gate_by_jm");
            ~nor_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatNorComp(const std::string &value);
    };

    class xnor_Comp : public Component {
        public:
            xnor_Comp(std::string name = "xnor_gate_by_jm");
            ~xnor_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatXnorComp(const std::string &value);
    };

    class not_Comp : public Component {
        public:
            not_Comp(std::string name = "not_gate_by_jm");
            ~not_Comp();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatNotComp(const std::string &value);
    };

    class comp4081 : public Component {
        public:
            comp4081(std::string name = "component4081_by_jm");
            ~comp4081();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4081Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class comp4071 : public Component {
        public:
            comp4071(std::string name = "component4071_by_jm");
            ~comp4071();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4071Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class comp4011 : public Component {
        public:
            comp4011(std::string name = "component4011_by_jm");
            ~comp4011();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4011Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class comp4001 : public Component {
        public:
            comp4001(std::string name = "component4001_by_jm");
            ~comp4001();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4001Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class comp4030 : public Component {
        public:
            comp4030(std::string name = "component4030_by_jm");
            ~comp4030();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4030Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class comp4069 : public Component {
        public:
            comp4069(std::string name = "component4069_by_jm");
            ~comp4069();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4069Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class comp4013 : public Component {
        public:
            comp4013(std::string name = "component4013_by_jm");
            ~comp4013();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creat4013Comp(const std::string &value);
        private:
            std::vector<std::unique_ptr<Component>> _parts;
    };

    class input :public Component {
        public:
            input(std::string name);
            ~input();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatInput(const std::string &value);
    };

    class trueC :public Component {
        public:
            trueC(std::string name);
            ~trueC();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatTrue(const std::string &value);
    };

    class falseC :public Component {
        public:
            falseC(std::string name);
            ~falseC();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatFalse(const std::string &value);
    };

    class clock :public Component {
        public:
            clock(std::string name);
            ~clock();
            void compute();
            void dump() const;
            static std::unique_ptr<Component> creatClock(const std::string &value);
    };

    class output :public Component {
        public:
            output(std::string name);
            ~output();
            void print_compute();
            void dump() const;
            static std::unique_ptr<Component> creatOutput(const std::string &value);
    };
}

#endif