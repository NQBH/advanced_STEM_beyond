function A = assemble_matrix(str_integrand_unknown, str_integrand_test, ...
    str_cofvar, mesh_geo, degree_FE, number)
% Assembly the finite-element matrix
% Author: Nguyen Quan Ba Hong
% Date: 15/10/2018
% Last Update: 6/11/2018
% Inputs:
% + str_integrand_unknown, str_integrand_test: character strings
% identifying the operators A & B (see function diff_op.m)
% + str_cofvar: character string identifying the function alpha(x)
% + mesh_geo: a mesh structure defining the geometry, if degree_FE = 1,
% this mesh structure must be a P_1 mesh structure, if degree_FE = 2, it
% must be modified into a P_2 mesh structure, before running this script
% + degree_FE: degree of the finite-element interpolation
% + number: identification number of the quadrature formula
% Output:
% + A: the assembled finite-element matrix

%% Points & Weights of Quadrature Formulas for the Reference Element
[points, weights] = quadrature(number); % Nodal Quadrature Formulas
% [points, weights] = Gausspoints(2); % Gaussian Quadrature Formulas

%% Main Loops
A = zeros(size(mesh_geo.coords,1)); % Initialzie
for K = 1:size(mesh_geo.triangles,1) % Loop on All Triangles of the Mesh Given
    % Coordinates of the Vertices of the K-th Triangle in the Mesh
    % the Vertices in P_K of this Triangle
    vertices = mesh_geo.coords(mesh_geo.triangles(K,:),:);
    % the Vertices in P_1 of this Triangle
    main_vertices = vertices([1,2,3],:);
    for q = 1:size(points,1) % Loop on All Quadrature Points
        % Evaluate the Nodal Basis Functions of the Reference Element at
        % the Quadrature Points
        [vals_hatphi, dervals_hatphi] = shape_fcts(points(q,:), degree_FE);
        % Evaluate the Geometric Basis Functions at the Quadrature Points
        [vals_hatpsi, dervals_hatpsi] = shape_fcts(points(q,:), 1); %P_1 Isoparametric
        % Evaluate the Geometric Function at the Quadrature Point
        geo_func = [dot(vals_hatpsi, main_vertices(:,1)), ...
            dot(vals_hatpsi, main_vertices(:,2))];
        % Evaluate the Jacobian Matrix of the Geometric Function at the
        % Quadrature Point
        jacob = compute_jacobian(main_vertices, dervals_hatpsi);
        % Compute the Gradient of the Function phi(x)
        dervals_phi = dervals_hatphi/jacob;
        for i = 1:size(mesh_geo.triangles,2) % Loop on the Node i of the Element K
            % Global Index of the Node i of the Element K
            I = mesh_geo.triangles(K, i);
            for j = 1:size(mesh_geo.triangles,2) % Loop on the Node j of the Element K
                % Global Index of the Node j of the Element K
                J = mesh_geo.triangles(K, j);
                % Add Contribution of (i,j) at the Quadrature Points
                A(I,J) = A(I,J) + weights(q)*feval(str_cofvar, geo_func)*...
                    diff_op(str_integrand_unknown, vals_hatphi(j), dervals_phi(j,:))*...
                    diff_op(str_integrand_test, vals_hatphi(i), dervals_phi(i,:))...
                    *abs(det(jacob));
            end
        end
    end
end

