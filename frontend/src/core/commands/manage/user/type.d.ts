declare namespace User {
  /**
   * 用户类型
   */
  interface UserType {
    id:number;
    userAccount: string;
    email?: string;
    createTime?: date;
    updateTime?: date;
    userRole?:number;
  }
}
