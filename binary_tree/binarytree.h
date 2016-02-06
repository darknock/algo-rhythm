#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <QQuickItem>
#include <binarysearchtree.h>

class BinaryNode : public QObject, public BinarySearchTree<int>::Node
{
    Q_OBJECT
    Q_PROPERTY(QPoint parentPos READ parentPos WRITE setParentPos NOTIFY parentPosChanged);
    Q_PROPERTY(QPoint offset READ offset WRITE setOffset NOTIFY offsetChanged);
    Q_PROPERTY(QPoint position READ position WRITE setPosition NOTIFY positionChanged);

public:

    BinaryNode ()
        : Node(0)
    {
    }

    BinaryNode (int value)
        : Node(value)
    {
    }

    Node* left() const override;
    void set_left(Node *node) override;
    Node* right() const override;
    void set_right(Node *node) override;

    QPoint offset();
    void setOffset(QPoint offset);
    QPoint parentPos();
    void setParentPos(QPoint pos);
    QPoint position();
    void setPosition(QPoint pos);

    Q_INVOKABLE int value() const;

signals:
    void leftChanged();
    void rightChanged();
    void parentPosChanged();
    void offsetChanged();
    void positionChanged();

private:
    BinaryNode *parent_;
    QPoint parent_pos_;
    QPoint offset_;
    QPoint position_;
};

class BinaryTree : public QObject
{
    Q_OBJECT
public:
    BinaryTree();
    Q_INVOKABLE BinaryNode* node(int value);
    Q_INVOKABLE bool insert(BinaryNode *node);
    Q_INVOKABLE void destroyNode(BinaryNode *node);

private:
    BinarySearchTree<int> tree_;
};

#endif // BINARYTREE_H
