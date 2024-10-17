#ifndef AFFINE_TOOLS_H
#define AFFINE_TOOLS_H

#include "../includes.h"
#include"../lab4/affine_transformations.h"

void offset_window();
void popup(string opt_name);
void turning_window();
void scaling_window();

bool show_offset_window = false; // ���� ��� ������ ���� ��������
bool show_turning_window = false; // ���� ��� ������ ���� �������� ��������
bool show_scaling_window = false; // ���� ��� ������ ���� �������� ��������
//bool show_warinig_window = false;
int offset_x = 0; // �������� �������� �� X
int offset_y = 0; // �������� �������� �� Y
int turning_value = 0;

string scaling_opt = "Scaling Options";
string turning_opt = "Turning Options";
//string warning;

AffineMatrix amatrix;

// ������� ������
ImVec2 button_size(75.0f, 25.0f); // ������ � ������ ������

void create_affine_tools() {

    ImGui::SetNextWindowSize(ImVec2(200, 150));

    ImGui::Begin("Affine tools");

    if (ImGui::Button("offset", button_size)) {
        show_offset_window = true;
    }
    if (ImGui::Button("Turning", button_size)) {
        ImGui::OpenPopup(turning_opt.c_str()); // ��������� ����������� ���� � �������

    }

    if (ImGui::Button("Scaling", button_size)) {
        ImGui::OpenPopup(scaling_opt.c_str());
    }

    popup(scaling_opt);
    popup(turning_opt);
    

    ImGui::End();


    if (show_offset_window) {
        offset_window();
    }

    if (show_turning_window) {
        turning_window();
    }

    if (show_scaling_window)
        scaling_window();
}

void popup(string opt_name) {
    if (ImGui::BeginPopup(opt_name.c_str())) { // �������� �������� ����������� ������
        if (ImGui::Selectable("Center")) {
            if (!show_offset_window) {
                amatrix.around_center = true;
                if (opt_name == turning_opt)
                    show_turning_window = true;
                else
                    show_scaling_window = true;
            }
        }
        if (ImGui::Selectable("Set a point")) {
            if (!show_offset_window) {
                if (ImGui::IsItemClicked()) {
                    ImVec2 mousePos = ImGui::GetMousePos();
                    amatrix.set_center_point(mousePos);
                    amatrix.around_center = false;
                    if (opt_name == turning_opt)
                        show_turning_window = true;
                    else
                        show_scaling_window = true;
                }
            }
        }
        ImGui::EndPopup(); // ����������� �������� ������������ ����
    }

}

void offset_window() {
    ImGui::Begin("Offset Settings", &show_offset_window); // �������� ������ �������� ����
    ImGui::InputInt("Offset X", &offset_x); // ���� ��� ����� �������� �� X
    ImGui::InputInt("Offset Y", &offset_y); // ���� ��� ����� �������� �� Y

    if (ImGui::Button("Apply")) {
        amatrix.make_offset(offset_x, offset_y);
        show_offset_window = false;
    }

    ImGui::SameLine();

    if (ImGui::Button("Cancel")) {
        show_offset_window = false;
    }

    ImGui::End();
}

void turning_window() {
    ImGui::Begin("Turning Settings", &show_turning_window); // �������� ������ �������� ����

    ImGui::InputInt("The angle in radians", &turning_value);


    if (ImGui::Button("Apply")) {
        amatrix.make_turning(turning_value);
        show_turning_window = false;
    }

    ImGui::SameLine();

    if (ImGui::Button("Cancel")) {
        show_turning_window = false;
    }

    ImGui::End();
}


void scaling_window() {

    ImGui::Begin("Scaling Settings", &show_turning_window); // �������� ������ �������� ����

    float scaling_value = 0;
    ImGui::InputFloat("The scaling", &scaling_value);


    if (ImGui::Button("Apply")) {
        amatrix.make_scaling(scaling_value);
        show_scaling_window = false;
    }

    ImGui::SameLine();

    if (ImGui::Button("Cancel")) {
        show_scaling_window = false;
    }

    ImGui::End();
}


#endif // !AFFINE_TRANSFORMATIONS_H
