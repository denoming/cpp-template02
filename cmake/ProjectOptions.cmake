include(FeatureSummary)

option(TEMPLATE02_ENABLE_TESTS "Enable testing" ON)
add_feature_info(
    ENABLE_TESTS TEMPLATE02_ENABLE_TESTS "Build project with tests"
)

feature_summary(WHAT ALL)
