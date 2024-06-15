package models

type TbUser struct {
	Id       int
	Username string
	Address  string
}

func (TbUser) TableName() string {
	return "tb_user"
}
