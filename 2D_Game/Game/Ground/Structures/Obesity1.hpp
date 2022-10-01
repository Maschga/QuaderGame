#pragma once

#include "Structure.hpp"

/* Represents a obesity-structure. */
class Obesity1 : public Structure {
public:
    using Structure::Structure;

    /* The destructor. */
    ~Obesity1();

    /* Initialises the blocks for the structure. */
    void create_blocks(float x, float y) override;
};