#include "binarytree.h"

#include <QDebug>

BinaryTree::BinaryTree()
{
}

Q_INVOKABLE BinaryNode* BinaryTree::node(int value)
{
    return new BinaryNode(value);
}

bool BinaryTree::insert(BinaryNode *node)
{
    return tree_.insert(node);
}

void BinaryTree::destroyNode(BinaryNode *node)
{
    delete node;
}

auto BinaryNode::left() const -> Node*
{
    return left_;
}

void BinaryNode::set_left(Node *node)
{
    if (left_ != node) {
        left_ = node;
        QPoint new_pos = position();
        new_pos.rx() -= offset().x();
        new_pos.ry() += offset().y();
        QPoint new_offset = offset();
        new_offset.rx() /= 2;
        static_cast<BinaryNode*>(left_)->setParentPos(position());
        static_cast<BinaryNode*>(left_)->setPosition(new_pos);
        static_cast<BinaryNode*>(left_)->setOffset(new_offset);
        leftChanged();
    }
}

auto BinaryNode::right() const -> Node*
{
    return right_;
}

void BinaryNode::set_right(Node *node)
{
    if (right_ != node) {
        right_ = node;
        QPoint new_pos = position();
        new_pos.rx() += offset().x();
        new_pos.ry() += offset().y();
        QPoint new_offset = offset();
        new_offset.rx() /= 2;
        static_cast<BinaryNode*>(right_)->setParentPos(position());
        static_cast<BinaryNode*>(right_)->setPosition(new_pos);
        static_cast<BinaryNode*>(right_)->setOffset(new_offset);
        rightChanged();
    }
}

int BinaryNode::value() const
{
    return value_;
}

QPoint BinaryNode::offset()
{
    return offset_;
}

void BinaryNode::setOffset(QPoint offset)
{
    if (offset_ != offset) {
        offset_ = offset;
        emit offsetChanged();
    }
}

QPoint BinaryNode::parentPos()
{
    return parent_pos_;
}

void BinaryNode::setParentPos(QPoint pos)
{
    if (parent_pos_ != pos) {
        parent_pos_ = pos;
        emit parentPosChanged();
    }
}

QPoint BinaryNode::position()
{
    return position_;
}

void BinaryNode::setPosition(QPoint pos)
{
    if (position_ != pos) {
        position_ = pos;
        emit positionChanged();
    }
}
