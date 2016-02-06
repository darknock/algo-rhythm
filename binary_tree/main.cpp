#include "binarytree.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 3) {
        if (argc == 2) {
            QGuiApplication app(argc, argv);
            QQmlApplicationEngine engine;
            qmlRegisterType<BinaryNode>("com.qlsystems.binary", 1, 0, "BinaryNode");
            qmlRegisterType<BinaryTree>("com.qlsystems.binary", 1, 0, "BinaryTree");
            engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

            return app.exec();
        } else {
            std::cout << "Usage: " << argv[0] << "<N> <n0 n1 n2 ...>\n";
            exit(-1);
        }
    }

    BinarySearchTree<int> tree;
    int N = atoi(argv[1]);
    if (N > argc - 2) {
        std::cerr << "Not enough input elements\n";
        exit(-1);
    }
    std::cout << "Size: " << N << std::endl;
    std::cout << "Input:       ";
    for(int i = 0; i < N; ++i) {
        int n = atoi(argv[i + 2]);
        std::cout << n << ' ';
        tree << n;
    }

    std::cout << std::endl << "Pre order:  ";
    tree.traverse([](int i) { std::cout << ' ' << i; }, tree.PRE_ORDER);
    std::cout << std::endl << "In order:   ";
    tree.traverse([](int i) { std::cout << ' ' << i; }, tree.IN_ORDER);
    std::cout << std::endl << "Post order: ";
    tree.traverse([](int i) { std::cout << ' ' << i; }, tree.POST_ORDER);
    std::cout << std::endl << "Level order:";
    tree.traverse([](int i) { std::cout << ' ' << i; }, tree.LEVEL_ORDER);
    std::cout << std::endl;

//    return 0;
}
