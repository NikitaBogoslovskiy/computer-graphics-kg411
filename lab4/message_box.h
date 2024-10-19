#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include"../includes.h"

extern bool show_message_box = false;

void ShowInfoWindow(string text = "")
{
    if (show_message_box)
    {
        // ������ �������� ����
        ImGui::Begin("Information", &show_message_box, ImGuiWindowFlags_AlwaysAutoResize);

        // ����� ���������
        ImGui::Text(text.c_str());

        // ������ OK
        if (ImGui::Button("OK"))
        {
            // ��������� ���� ��� �������
            show_message_box = false;
        }

        // ���������� �������� ����
        ImGui::End();
    }
}

#endif // !MESSAGE_BOX_H
