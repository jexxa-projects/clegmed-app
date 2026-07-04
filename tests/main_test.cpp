#include <gtest/gtest.h>
#include <clegmed/core/flowgraph/FlowGraph.hpp>
#include <clegmed/plugins/shortcuts.hpp>
#include <string>
#include <vector>
#include "Await.hpp"

TEST(CLegMedTemplateTestSuite, BasicPipelineFlow) {
    using namespace clegmed::shortcuts;

    std::vector<std::string> received_data;

    auto flowgraph = FlowGraph{}
        .every(10ms)
        .from(emit("TestMessage"))
        .then(passThrough())
        .consumeWith(store(received_data));

    flowgraph.start();

    await_condition(2s, [&] {return !received_data.empty();} );
    EXPECT_EQ(received_data.at(0), "TestMessage");

    flowgraph.stop();
}
