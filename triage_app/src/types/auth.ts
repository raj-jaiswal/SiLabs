export type UserRole = 'ADMIN' | 'USER';

export interface UserAccount {
  id: string;
  name: string;
  email: string;
  password: string;
  role: UserRole;
  createdAt: string;
}

export interface ActiveSession {
  user: UserAccount;
  loginTime: string;
}

export interface PatientDispatchAssignment {
  id: string;
  targetUserId: string;
  patientId: string;
  patientNumber: string;
  note: string;
  dispatchedAt: string;
  status: 'PENDING' | 'ACKNOWLEDGED';
}
