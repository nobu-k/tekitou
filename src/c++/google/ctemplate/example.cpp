#include <cstdlib>
#include <string>
#include <iostream>
#include <ctemplate/template.h>

int main(int argc, char** argv)
{
  ctemplate::TemplateDictionary dict("example");
  dict.SetValue("NAME", "John Smith");
  int winnings = rand() % 100000;
  dict.SetIntValue("VALUE", winnings);
  dict.SetFormattedValue("TAXED_VALUE", "%.2f", winnings * 0.83);
  if (1) {
    dict.ShowSection("IN_CA");
    dict.ShowSection("IN_CA"); // this effects only once

    // add new section
    dict.SetValueAndShowSection("TAXED_VALUE", "100", "IN_CA");

    // add new section by different way
    ctemplate::TemplateDictionary* sub1 = dict.AddSectionDictionary("IN_CA");
    sub1->SetValue("TAXED_VALUE", "12345");

    ctemplate::TemplateDictionary* sub2 = dict.AddSectionDictionary("IN_CA");
    // sub2->SetValue("TAXED_VALUE", "98765"); // TAXED_VALUE in dict will be used
  }
  ctemplate::Template* tpl = ctemplate::Template::GetTemplate("example.tpl",
                                                              ctemplate::DO_NOT_STRIP);
  std::string output;
  tpl->Expand(&output, &dict);
  std::cout << output;
  return 0;
}
