declare namespace User {
  /**
   * 用户类型
   */
  interface UserType {
    userAccount: string;
    email?: string;
    createTime?: date;
    updateTime?: date;
  }
}
