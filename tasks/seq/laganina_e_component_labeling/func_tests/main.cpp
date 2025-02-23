#include <gtest/gtest.h>

#include <vector>

#include "core/task/include/task.hpp"
#include "core/util/include/util.hpp"
#include "seq/laganina_e_component_labeling/include/ops_seq.hpp"

TEST(laganina_e_component_labeling_seq, validation_test1) {
  int m_ = 0;
  int n_ = -1;
  // Create data
  std::vector<int> in(m_ * n_, 0);
  std::vector<int> out(m_ * n_, 0);
  // Create task_data
  auto task_data_seq = std::make_shared<ppc::core::TaskData>();
  task_data_seq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  task_data_seq->inputs_count.emplace_back(reinterpret_cast<uint8_t>(m_));
  task_data_seq->inputs_count.emplace_back(reinterpret_cast<uint8_t>(n_));
  task_data_seq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  task_data_seq->outputs_count.emplace_back(reinterpret_cast<uint8_t>(m_));
  task_data_seq->outputs_count.emplace_back(reinterpret_cast<uint8_t>(n_));

  // Create Task
  laganina_e_component_labeling_seq::TestTaskSequential test_task_sequential(task_data_seq);
  ASSERT_EQ(test_task_sequential.Validation(), false);
  test_task_sequential.PreProcessing();
}
