#pragma once
enum TextColor {GreenText = 2, BlueText = 3, WhiteText = 15};

void PrintColorText(const char *text, TextColor tc = TextColor::GreenText);
