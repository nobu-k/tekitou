#include <iostream>
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
using namespace std;

void printElements(xmlNode* node)
{
  for (xmlNode* cur = node; cur != NULL; cur = cur->next) {
    if (cur->type == XML_TEXT_NODE) {
      cout << cur->content << endl;
      // or
      // cout << xmlNodeGetContent(cur) << endl;
    } else if (cur->type == XML_CDATA_SECTION_NODE) {
      cout << "<![CDATA[" << cur->content << "]]>" << endl;
    } else if (cur->type == XML_ELEMENT_NODE) {
      cout << "<" << cur->name;
      for (xmlAttr* attr = cur->properties; attr != NULL; attr = attr->next) {
        cout << endl << " " << attr->name << "=\""
             << attr->children->content << "\"";
      }
      cout << ">" << endl;
    }

    printElements(cur->children);

    if (cur->type == XML_ELEMENT_NODE) {      
      cout << "</" << cur->name << ">" << endl;
    }
  }
}

int main(int argc, char* argv[])
{
  if (argc != 2) {
    return -1;
  }

  htmlDocPtr doc = htmlReadFile(argv[1], NULL,
                                HTML_PARSE_RECOVER);
  if (doc == NULL) {
    cerr << "failed to parse the file: " << argv[1] << endl;
  }

  xmlNode* root = xmlDocGetRootElement(doc);
  if (root == NULL) {
    cerr << "failed to get root element" << endl;
    return -1;
  }
  printElements(root);
  xmlFreeDoc(doc);
  xmlCleanupParser();
  return 0;
}
