#include <iostream>
#include <string>
#include <algorithm>  

class Text {
public:
    virtual ~Text() {}
    virtual void render(const std::string& data) = 0;
};


class PlainText : public Text {
public:
    void render(const std::string& data) override {
        std::cout << data;
    }
};

class Paragraph : public Text {
private:
    Text* text_;
public:
    Paragraph(Text* text) : text_(text) {}

    void render(const std::string& data) override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>" << std::endl;
    }
};


class Reversed : public Text {
private:
    Text* text_;
public:
    Reversed(Text* text) : text_(text) {}

    void render(const std::string& data) override {
        std::string reversed = data;
        std::reverse(reversed.begin(), reversed.end());
        text_->render(reversed);
    }
};

class Link : public Text {
private:
    Text* text_;
public:
    Link(Text* text) : text_(text) {}

 
    void render(const std::string& data) override {

        std::cout << data;
    }

    void render(const std::string& url, const std::string& data) {
        std::cout << "<a href=" << url << ">";
        text_->render(data);
        std::cout << "</a>" << std::endl;
    }
};


int main() {
    std::cout << "Paragraph" << std::endl;
    Text* text_block1 = new Paragraph(new PlainText());
    text_block1->render("Hello world");
    delete text_block1;

    std::cout << "\nReversed" << std::endl;
    Text* text_block2 = new Reversed(new PlainText());
    text_block2->render("Hello world");
    std::cout << std::endl;
    delete text_block2;

    std::cout << "\nLink" << std::endl;
    Link* text_block3 = new Link(new PlainText());
    text_block3->render("netology.ru","Hello world");
    delete text_block3;

    return 0;
}