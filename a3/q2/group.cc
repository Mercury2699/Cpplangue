#include "group.h" 

EmailNode::EmailNode(const std::string & email) 
	: email{email}, nextEmail{nullptr} {}

EmailNode::~EmailNode(){
	delete nextEmail;
}

GroupNode::GroupNode(Group * group) 
	: thisGroup{group}, nextGroup{nullptr} {}

GroupNode::~GroupNode() {
	delete nextGroup;
	delete thisGroup;
}

Group::Group(const std::string & name) 
	: groupname{name}, eList{nullptr}, gList{nullptr} {}

Group::~Group(){
	delete eList;
	delete gList;
}

std::string Group::name() const {
	return groupname;
}

std::string Group::emails() const {
	std::string emails = "[";
	for(EmailNode * head = eList; head; head = head->nextEmail) {
		emails += head->email;
		if (head->nextEmail) emails += ", ";
	}
	emails += "]";
	return emails;
}

void Group::addGroup(Group * group) {
	GroupNode * list = this->gList;
	GroupNode * add = new GroupNode(group);
	if (!list || group->groupname < list->thisGroup->groupname) {
		add->nextGroup = list;
		gList = add;
		return;
	}
	for (;list->nextGroup && 
		group->groupname > list->nextGroup->thisGroup->groupname; 
		list = list->nextGroup) {}
	add->nextGroup = list->nextGroup;
	list->nextGroup = add;
}

void Group::addAddress(const std::string & name) {
	EmailNode * l = eList;
	EmailNode * add = new EmailNode(name);
	if (!l || name < l->email) {
		add->nextEmail = l;
		eList = add;
		return;
	}
	for (;l->nextEmail && name > l->nextEmail->email; l = l->nextEmail) {}
	add->nextEmail = l->nextEmail;
	l->nextEmail = add;
}

bool Group::removeGroup(const std::string & name) {
	if (findGroup(name)){
		GroupNode * prev = gList;
		if (gList->thisGroup->groupname == name) {
			gList = gList->nextGroup;
			prev->nextGroup = nullptr;
			delete prev; // calls groupNode dtor
			return true;  
		}
		GroupNode * curr = prev->nextGroup;
		while (curr) {
			if (curr->thisGroup->groupname == name) {
				prev->nextGroup = curr->nextGroup;
				curr->nextGroup = nullptr; //don wanna delete others
				delete curr; // calls groupNode dtor
				return true; 
			}
			prev = curr;
			curr = curr->nextGroup;
		}
		for(GroupNode * l = gList; l; l = l->nextGroup) {
			bool ret = l->thisGroup->removeGroup(name);
			if (ret) return ret;
		}
	}
	return false;
}

bool Group::removeAddress(const std::string & name) {
	if (findAddress(name)){
		EmailNode * prev = eList;
		if (eList->email == name) {
			eList = eList->nextEmail; 
			prev->nextEmail = nullptr; // don wanna remove others
			delete prev; // calls emailNode dtor
			return true;
		}
		for(EmailNode * curr = eList->nextEmail; curr; prev=curr, curr=curr->nextEmail){
			if(curr->email == name) {
				prev->nextEmail = curr->nextEmail;
				curr->nextEmail = nullptr; // don wanna remove others
				delete curr; // calls emailNode dtor
				return true;
			}
		}
		for(GroupNode * l = gList; l; l = l->nextGroup) {
			bool ret = l->thisGroup->removeAddress(name);
			if (ret) return ret;
		}
	}
	return false;
}

GroupNode * Group::findGroup(const std::string & name) {
	for(GroupNode * l = gList; l; l = l->nextGroup) {
		if (l->thisGroup->groupname == name) return l;
	}
	for(GroupNode * l = gList; l; l = l->nextGroup) {
		GroupNode * ret = l->thisGroup->findGroup(name);
		if (ret) return ret;
	}
	return nullptr;
}

EmailNode * Group::findAddress(const std::string & name) {
	for(EmailNode * l = eList; l; l = l->nextEmail) {
		if (l->email == name) return l;
	}
	for(GroupNode * gL = gList; gL; gL = gL->nextGroup) {
		EmailNode * ret = gL->thisGroup->findAddress(name);
		if (ret) return ret;
	}
	return nullptr;
}

void indent(int level) {
	for (; level > 0; level--) {
		std::cout << "\t";
	}
}

std::ostream & printGroup(std::ostream& out, Group & Group, int level) {
	if (level <= 0) {
		out << Group.groupname << std::endl;
		out << Group.emails() << std::endl;
	} else {
		indent(level);
		out << Group.groupname << std::endl;
		indent(level);
		out << Group.emails() << std::endl;
	}
	if (Group.gList) {
		for(GroupNode * n = Group.gList; n; n = n->nextGroup) {
			printGroup(out, *(n->thisGroup), level + 1);
		}
	}
	return out;
}

std::ostream & operator<<(std::ostream& out, Group & group) {
	// out << group.groupname << std::endl;
	// out << group.emails() << std::endl;
	// if (group.gList) {
	// 	for(GroupNode * n = group.gList; n; n = n->nextGroup) {
	// 		out << "\t" << *(n->thisGroup);
	// 	}
	// }
	return printGroup(out, group, 0);
}

std::ostream & operator<<(std::ostream& out, GroupNode & groupNode) {
	out << groupNode.thisGroup->groupname << std::endl;
	out << groupNode.thisGroup->emails() << std::endl;
	return out;
}

std::ostream & operator<<(std::ostream& out, EmailNode & emailNode) {
	return out << emailNode.email;
}



