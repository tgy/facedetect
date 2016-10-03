#pragma once

#include "classifier.hh"

using data_t = std::vector<std::pair<std::vector<unsigned char>, char>>;

/* Train a classifier
**
** Parameters
** ----------
** positive_path : string
**     Path to the directory containing positive windows examples
**
** negative_path : string
**     Path to the directory containing negative windows examples
**
** Return
** ------
** classifier : mblbp_classifier
**     Trained classifier
*/
mblbp_classifier train(const std::string &positive_path,
                       const std::string &negative_path);

void attentional_cascade(mblbp_classifier &cascade,
                         data_t &training_set,
                         data_t &validation_set,
                         std::vector<weak_classifier>& all_weak_classifiers);

void train_strong_classifier(strong_classifier &str_classifier, data_t &training_set, std::vector<weak_classifier>& all_weak_classifiers);

void attentional_cascade_aux(strong_classifier &str_classifier,
                             data_t &training_set,
                             data_t &validation_set,
                             std::vector<weak_classifier>& all_weak_classifiers,
                             double &gamma_0_prime,
                             double &sl, bool &sl_trajectory, int &layer_count, double &u);

void attentional_cascade_add_weak_classifier(strong_classifier &str_classifier,
                                             data_t &training_set,
                                             data_t &validation_set,
                                             std::vector<weak_classifier>& all_weak_classifiers,
                                             double &gamma_0_prime,
                                             double &sl, bool &sl_trajectory, int &layer_count, double &u);
